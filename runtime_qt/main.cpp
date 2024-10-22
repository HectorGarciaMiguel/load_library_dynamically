#include <QDebug>
#include <QLibrary>

#define WORKAROUND

typedef int (*GetVariable)();
typedef void (*SetVariable)(int);

// ------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    (void) argc;
    (void) argv;

    QLibrary coreLib1("core");

#ifdef WORKAROUND
    // PRE: copy libcore.so to libcore2.so
    QLibrary coreLib2("core2");
#else
    QLibrary coreLib2("core");
#endif

    if (coreLib1.load() == false)
    {
        qDebug() << "error core 1 not load";
        return 1;
    }

    if (coreLib2.load() == false)
    {
        qDebug() << "error core 2 not load";
        return 1;
    }

    GetVariable getFrom1 = (GetVariable)coreLib1.resolve("_get");
    GetVariable getFrom2 = (GetVariable)coreLib2.resolve("_get");
    SetVariable setFrom1 = (SetVariable)coreLib1.resolve("_set");
    SetVariable setFrom2 = (SetVariable)coreLib2.resolve("_set");

    qDebug() << "runtime_qt: creation core1" << getFrom1();
    qDebug() << "runtime_qt: creation core2" << getFrom2();

    qDebug() << "-------------------";
    setFrom1(25);
    qDebug() << "runtime_qt: after set core1 core1 =" << getFrom1();
    qDebug() << "runtime_qt: after set core1 core2 =" << getFrom2();

    qDebug() << "-------------------";
    setFrom2(30);
    qDebug() << "runtime_qt: after set core2 core1 =" << getFrom1();
    qDebug() << "runtime_qt: after set core2 core2 =" << getFrom2();

    if (coreLib1.isLoaded())
        coreLib1.unload();

    if (coreLib2.isLoaded())
        coreLib2.unload();

    return 0;
}
