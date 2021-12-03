
#include <iostream>
#include <type_traits>
#include "type_defs.h"

template<int i>
class Loop {
public:
    static inline void execute()
    {
        std::cout << "Item #" << i << std::endl;
        Loop<i - 1>::execute();
    }
};

template<>
class Loop<0> {
public:
    static inline void execute()
    {
    }
};

template<class T>
constexpr T MaxValue(T a, T b)
{
    return (a > b) ? a : b;
}

template<int start, int increment, int end>
class ForLoop {
public:
    static inline void execute()
    {
        std::cout << "Item #" << start << std::endl;
        ForLoop<start + increment, increment, MaxValue<int>(end - increment, 0)>::execute();
    }
};

template<int start, int increment>
class ForLoop<start, increment, 0> {
public:
    static inline void execute()
    {

    }
};

