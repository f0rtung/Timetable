#include "timetable.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Timetable w;
    w.show();

    return a.exec();
}
