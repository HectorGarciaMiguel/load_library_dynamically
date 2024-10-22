#ifdef Q_OS_WIN
#define CORE_EXPORT __declspec(dllexport)
#else
#define CORE_EXPORT
#endif
