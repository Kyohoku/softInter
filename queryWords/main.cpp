#include "widget.h"
#include "login.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login w;
    w.show();
//    Widget w;
//    w.show();
    return a.exec();
}
