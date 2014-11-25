#include "locadoraqt.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LocadoraQT w;
    w.show();
    return a.exec();
}
