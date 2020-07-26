#include <QApplication>
#include "snake.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    snake windows;

    windows.setWindowTitle("Snake");
    windows.show();
    return app.exec();
}
