#include <dlfcn.h>
#include <QDebug>

typedef int (*GetVariable)();
typedef void (*SetVariable)(int);

// ------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    (void) argc;
    (void) argv;

    void* handle1 = dlmopen(LM_ID_NEWLM, "./libcore.so", RTLD_LAZY);
    if (!handle1)
    {
        qDebug() << "error core 1 not load";
        return EXIT_FAILURE;
    }

    void* handle2 = dlmopen(LM_ID_NEWLM, "./libcore.so", RTLD_LAZY);
    if (!handle2)
    {
        qDebug() << "error core 2 not load";
        return EXIT_FAILURE;
    }

    GetVariable getFrom1 = (GetVariable) dlsym(handle1, "_get");
    if (!getFrom1)
    {
        qDebug() << "error no such symbol getFrom1";
        dlclose(handle1);
        return EXIT_FAILURE;
    }

    GetVariable getFrom2 = (GetVariable) dlsym(handle2, "_get");
    if (!getFrom2)
    {
        qDebug() << "error no such symbol getFrom2";
        dlclose(handle2);
        return EXIT_FAILURE;
    }

    SetVariable setFrom1 = (SetVariable) dlsym(handle1, "_set");
    if (!setFrom1)
    {
        qDebug() << "error no such symbol setFrom1";
        dlclose(handle1);
        return EXIT_FAILURE;
    }

    SetVariable setFrom2 = (SetVariable) dlsym(handle2, "_set");
    if (!setFrom2)
    {
        qDebug() << "error no such symbol setFrom2";
        dlclose(handle2);
        return EXIT_FAILURE;
    }

    qDebug() << "runtime_native: creation core1" << getFrom1();
    qDebug() << "runtime_native: creation core2" << getFrom2();

    qDebug() << "-------------------";
    setFrom1(25);
    qDebug() << "runtime_native: after set core1 core1 =" << getFrom1();
    qDebug() << "runtime_native: after set core1 core2 =" << getFrom2();

    qDebug() << "-------------------";
    setFrom2(30);
    qDebug() << "runtime_native: after set core2 core1 =" << getFrom1();
    qDebug() << "runtime_native: after set core2 core2 =" << getFrom2();

    dlclose(handle1);
    dlclose(handle2);

    return 0;
}
