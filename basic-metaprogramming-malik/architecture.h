
#pragma once
#ifndef CHALLENGE_ARCHITECTURE_H_
#define CHALLENGE_ARCHITECTURE_H_

#include <string>
#include <iostream>

template<std::size_t B = sizeof(void*)>
struct Architecture
{
    // constexpr static const unsigned short int value = Architecture<(B == 0) ? sizeof(void*) : B>::value;
    constexpr static const unsigned short int value = Architecture<B>::value;
};

template<>
struct Architecture<4>
{
    constexpr static const unsigned short int value = 32;
};

template<>
struct Architecture<8>
{
    constexpr static const unsigned short int value = 64;
};

#endif
