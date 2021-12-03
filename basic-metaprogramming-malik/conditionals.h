
#ifndef CONDITIONALS_H_
#define CONDITIONALS_H_

#include "type_defs.h"

template <bool condition>
struct If {};

template <>
struct If<true>
{
    static inline void run(func t, func f)
    {
        t();
    }
};

template <>
struct If<false>
{
    static inline void run(func t, func f)
    {
        f();
    }
};

#endif
