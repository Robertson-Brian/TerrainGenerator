#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_MainWindow.h"
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

#include <RInside.h>

class vtkRenderer;
class vtkEventQtSlotConnect;
class vtkObject;
class vtkCommand;
class vtkContextView;

//namespace Ui {
//class MainWindow;
//}

class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    
    MainWindow(RInside & R);
    ~MainWindow();
    
    RInside & m_R;

private:
//    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H












