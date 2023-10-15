#include "T_Project.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    T_Project w;
    w.show();
    return a.exec();
}
