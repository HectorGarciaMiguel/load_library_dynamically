#include <QDebug>
#include <QObject>

#include "include/core.h"

// ------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    (void) argc;
    (void) argv;

    Core core1;
    qDebug() << "header: creation core1" << core1.get();

    Core core2;
    qDebug() << "header: creation core2" << core2.get();

    qDebug() << "-------------------";
    core1.set(25);
    qDebug() << "header: after set core1 core1 =" << core1.get();
    qDebug() << "header: after set core1 core2 =" << core2.get();

    qDebug() << "-------------------";
    core2.set(30);
    qDebug() << "header: after set core2 core1 =" << core1.get();
    qDebug() << "header: after set core2 core2 =" << core2.get();

    return 0;
}
