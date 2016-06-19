/*=========================================================================

  Program:   Visualization Toolkit
  Module:    GUI1.cxx
=========================================================================*/
#include "GUI1.h"

#include <vtkCamera.h>
#include <vtkDelaunay2D.h>
#include <vtkLookupTable.h>
#include <vtkPoints.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkQuadricLODActor.h>

#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>
#include <vtkVertexGlyphFilter.h>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

#include <string>
#include <cstring>

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdlib.h>

ofstream OPR;

GUI1::GUI1()
{
    this->setupUi(this);

    // create a window and give it to QVTKWidget
    vtkRenderWindow* renwin = vtkRenderWindow::New();
    qVTK1->SetRenderWindow(renwin);
    renwin->Delete();
    QVTKInteractor *iren = this->qVTK1->GetInteractor();

//    iren->SetDesiredUpdateRate(2);

    // add a renderer
    Ren1 = vtkRenderer::New();
    qVTK1->GetRenderWindow()->AddRenderer(Ren1);

    // sizes - 129, 257, 513, 1025, 2049, 4097, 8193, 16385, 32768
    squareSide = 257; //odd numbers only
    viewSize = 257;
    xStart = 0;
    yStart = 0;

    heightMax = 0.0;
    heightMin = 0.0;

    for(int i = 0; i < squareSide; ++i)
    {
        zPoint[i] = new float[squareSide];
    }

    //initialize to zero
    for(int x = 0; x < squareSide; x++) //x
    {
        for(int y = 0; y < squareSide; y++)//y
        {
            zPoint[y][x] = 0.0;//((((rand()%1000)/500.0)-1)/4);
        }
    }

    connect(pushButton, SIGNAL (released()),this, SLOT (renderSection()));


}

GUI1::~GUI1()
{
	Ren1->Delete();
}

void GUI1::renderSection()
{
    zSteps();

    srand(time(NULL));

    vtkSmartPointer<vtkPoints> points =
    vtkSmartPointer<vtkPoints>::New();

    for(int x = xStart; x < (xStart + viewSize); x++) //x
    {
        for(int y = yStart; y < (yStart + viewSize); y++)//y
        {
            points->InsertNextPoint(x,y,zPoint[x][y]);
        }
    }

    vtkSmartPointer<vtkPolyData> pointsPolydata =
        vtkSmartPointer<vtkPolyData>::New();

    pointsPolydata->SetPoints(points);

    vtkSmartPointer<vtkVertexGlyphFilter> vertexFilter =
        vtkSmartPointer<vtkVertexGlyphFilter>::New();

    vertexFilter->SetInputData(pointsPolydata);

    vertexFilter->Update();

    vtkSmartPointer<vtkPolyData> polydata =
        vtkSmartPointer<vtkPolyData>::New();
    polydata->ShallowCopy(vertexFilter->GetOutput());

    // Triangulate the grid points
    vtkSmartPointer<vtkDelaunay2D> delaunay =
      vtkSmartPointer<vtkDelaunay2D>::New();

    delaunay->SetInputData(polydata);

    delaunay->Update();
    vtkPolyData* outputPolyData = delaunay->GetOutput();

////////////////////////////////////////////////////////////////////////////////
    cout << "heightMax " << heightMax << endl;
    cout << "heightMin " << heightMin << endl;
    // Create the color map
    vtkSmartPointer<vtkLookupTable> colorLookupTable =
      vtkSmartPointer<vtkLookupTable>::New();
    colorLookupTable->SetTableRange(heightMin, heightMax);
    colorLookupTable->Build();

    // Generate the colors for each point based on the color map
    vtkSmartPointer<vtkUnsignedCharArray> colors2 =
      vtkSmartPointer<vtkUnsignedCharArray>::New();
    colors2->SetNumberOfComponents(3);
    colors2->SetName("Colors2");

//    std::cout << "There are " << outputPolyData->GetNumberOfPoints()
//              << " points." << std::endl;

    for(int i = 0; i < outputPolyData->GetNumberOfPoints(); i++)
      {
          double p[3];
          outputPolyData->GetPoint(i,p);

          double dcolor[3];
          colorLookupTable->GetColor(p[2], dcolor); //---
//          std::cout << "dcolor: " << dcolor[0] << " " << dcolor[1] << " " << dcolor[2] << std::endl;
          unsigned char color[3];

            color[2] = static_cast<unsigned char>(255.0 * dcolor[0]);
            color[1] = static_cast<unsigned char>(255.0 * dcolor[1]);
            color[0] = static_cast<unsigned char>(255.0 * dcolor[2]);

//          std::cout << "color: " << (int)color[0] << " " << (int)color[1] << " " << (int)color[2] << std::endl;

          colors2->InsertNextTupleValue(color);
      }

    outputPolyData->GetPointData()->SetScalars(colors2);
////////////////////////////////////////////////////////////////////////////////

    // Create a mapper and actor
    vtkSmartPointer<vtkPolyDataMapper> mapper2 =
      vtkSmartPointer<vtkPolyDataMapper>::New();

    mapper2->SetInputData(outputPolyData);


    vtkSmartPointer<vtkActor> actor2 =
      vtkSmartPointer<vtkActor>::New();
    actor2->SetMapper(mapper2);

//    vtkSmartPointer<vtkQuadricLODActor> actor2 =
//        vtkSmartPointer<vtkQuadricLODActor>::New();
//    actor2->SetMapper(mapper2);

    // Visualization
    vtkSmartPointer<vtkPolyDataMapper> mapper =
        vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputData(polydata);

    vtkSmartPointer<vtkActor> actor =
        vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    actor->GetProperty()->SetPointSize(1);

//    Ren1->ResetCamera();

    Ren1->GetActiveCamera()->SetPosition(xStart+(viewSize/2), yStart+(viewSize/2), 400);
    Ren1->GetActiveCamera()->SetFocalPoint(xStart+(viewSize/2), yStart+(viewSize/2), 5);

    Ren1->RemoveAllViewProps();

    //	Ren1->GetActiveCamera()->SetViewUp(0, 0, 1);
    //	Ren1->SetBackground(.8, .8, .8); // Background color

//    Ren1->AddViewProp(actor);
    Ren1->AddViewProp(actor2);

    Ren1->GetRenderWindow()->Render();
}

void GUI1::zSteps()
{
    generateTerrain(0, 0, squareSide-1, squareSide-1, (squareSide/4), (squareSide-1));

    for(int x = xStart; x < (xStart + viewSize); x++) //x
    {
        for(int y = yStart; y < (yStart + viewSize); y++)//y
        {
            if(zPoint[x][y] > heightMax) heightMax = zPoint[x][y];
            if(zPoint[x][y] < heightMin) heightMin = zPoint[x][y];

        }
    }
}

// check out vtk LOD stuff

void GUI1::generateTerrain(unsigned x1, unsigned y1, unsigned x2, unsigned y2, float range, unsigned level) {
        if (level < 1) return;
//        cout << "Level " << level << endl;
//        cout << "range " << range << endl;

    // diamonds
    for (unsigned i = x1 + level; i < x2; i += level)
        for (unsigned j = y1 + level; j < y2; j += level)
        {
            float a = zPoint[i - level][j - level];
            float b = zPoint[i][j - level];
            float c = zPoint[i - level][j];
            float d = zPoint[i][j];
            float e = zPoint[i - level / 2][j - level / 2] = (a + b + c + d) / 4 + (((rand()%1000)/500.0)-1) * range;
        }

    // squares
    for (unsigned i = x1 + 2 * level; i < x2; i += level)
        for (unsigned j = y1 + 2 * level; j < y2; j += level)
        {
            float a = zPoint[i - level][j - level];
            float b = zPoint[i][j - level];
            float c = zPoint[i - level][j];
            float d = zPoint[i][j];
            float e = zPoint[i - level / 2][j - level / 2];

            float f = zPoint[i - level][j - level / 2] = (a + c + e + zPoint[i - 3 * level / 2][j - level / 2]) / 4 + (((rand()%1000)/500.0)-1) * range;
            float g = zPoint[i - level / 2][j - level] = (a + b + e + zPoint[i - level / 2][j - 3 * level / 2]) / 4 + (((rand()%1000)/500.0)-1) * range;
        }

        generateTerrain(x1, y1, x2, y2, range / 2, level / 2);
}
