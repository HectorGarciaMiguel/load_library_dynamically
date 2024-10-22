#ifndef CORE_H
#define CORE_H

#include "exports.h"

class CORE_EXPORT Core
{
public:

    static int s_variable;

    explicit Core();

    void set(const int);
    int get();
};

#endif // CORE_H
