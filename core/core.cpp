#include "core.h"


int Core::s_variable = 0;

// ------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------
Core::Core(){}

// ------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------
void Core::set(const int value)
{
    s_variable = value;
}

// ------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------
int Core::get()
{
    return s_variable;
}

#include "core_exports.cpp"
