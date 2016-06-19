#ifndef _GUI1_h
#define _GUI1_h

#include <QMainWindow>
#include "ui_GUI1.h"

#include <QMenu>
#include <QFileDialog>
#include <QFileInfo>
#include <QListWidget>
#include <QDebug>
#include <QAbstractItemModel>
#include <QItemSelectionModel>
#include <QModelIndex>
#include <QClipboard>
#include <QSvgWidget>
#include <QPushButton>
#include <QMessageBox>

#include <vtkImageData.h>
#include <vtkImageDataGeometryFilter.h>
#include <vtkDoubleArray.h>
#include <vtkPointData.h>
#include <vtkWarpScalar.h>
#include <vtkMergeFilter.h>
#include <vtkDataSetMapper.h>
#include <vtkActor.h>
#include <QListWidget>
#include <QTableWidget>
#include <vtkContextView.h>
#include <QTemporaryFile>
#include <QSvgWidget>
#include <QPushButton>


class vtkRenderer;
class vtkEventQtSlotConnect;
class vtkObject;
class vtkCommand;
class vtkContextView;

class GUI1 : public QMainWindow, public Ui::GUI1
{
    Q_OBJECT
    public:
        GUI1();
        ~GUI1();

private :

    int squareSide;

    int viewSize;
    int xStart;
    int yStart;

    double heightMax;
    double heightMin;

    float **zPoint = new float*[1000000];    // 2 dimensional array setup

    void generateTerrain(unsigned, unsigned, unsigned, unsigned, float, unsigned);

protected:
    vtkSmartPointer<vtkRenderer> Ren1;

public slots:

    void renderSection();
    void zSteps();
};



#endif // _GUI1_h
