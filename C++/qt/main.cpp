#include <QApplication>
#include "MyWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyWindow *win = new MyWindow(0);

    win->show();

    str *n = new str;

    QObject::connect(window, SIGNAL(Simple(QString)), n, SLOT(Simple(QString)));
    QObject::connect(window, SIGNAL(Invers(QString)), n, SLOT(Inversia(QString)));

    return a.exec();
}