/********************************************************************************
** Form generated from reading UI file 'GUI1.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI1_H
#define UI_GUI1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_GUI1
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget_2;
    QWidget *tab;
    QGridLayout *gridLayout;
    QVTKWidget *qVTK1;
    QPushButton *pushButton;
    QWidget *tab_2;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GUI1)
    {
        if (GUI1->objectName().isEmpty())
            GUI1->setObjectName(QStringLiteral("GUI1"));
        GUI1->resize(857, 548);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GUI1->sizePolicy().hasHeightForWidth());
        GUI1->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(GUI1);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tabWidget_2 = new QTabWidget(centralWidget);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setMinimumSize(QSize(200, 100));
        tabWidget_2->setMaximumSize(QSize(1920, 1080));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        qVTK1 = new QVTKWidget(tab);
        qVTK1->setObjectName(QStringLiteral("qVTK1"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(qVTK1->sizePolicy().hasHeightForWidth());
        qVTK1->setSizePolicy(sizePolicy1);
        qVTK1->setMinimumSize(QSize(200, 100));
#ifndef QT_NO_TOOLTIP
        qVTK1->setToolTip(QStringLiteral(""));
#endif // QT_NO_TOOLTIP

        gridLayout->addWidget(qVTK1, 0, 0, 1, 1);

        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        pushButton->setMinimumSize(QSize(75, 22));
        pushButton->setMaximumSize(QSize(400, 22));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        tabWidget_2->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget_2->addTab(tab_2, QString());

        gridLayout_2->addWidget(tabWidget_2, 0, 0, 1, 1);

        GUI1->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GUI1);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 857, 20));
        GUI1->setMenuBar(menuBar);
        statusBar = new QStatusBar(GUI1);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GUI1->setStatusBar(statusBar);

        retranslateUi(GUI1);

        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(GUI1);
    } // setupUi

    void retranslateUi(QMainWindow *GUI1)
    {
        GUI1->setWindowTitle(QApplication::translate("GUI1", "Terrain Generator", 0));
        pushButton->setText(QApplication::translate("GUI1", "Generate Terrain", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab), QApplication::translate("GUI1", "Tab 1", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QApplication::translate("GUI1", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class GUI1: public Ui_GUI1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI1_H
