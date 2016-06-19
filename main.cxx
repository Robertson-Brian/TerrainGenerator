#include <QVTKApplication.h>
#include <iostream>
#include "GUI1.h"

int main(int argc, char** argv)
{
    QVTKApplication app(argc, argv);
    GUI1 	   widget;

    widget.show();

  return app.exec();
}
