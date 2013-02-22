#ifndef __ERROR_H_
#define __ERROR_H_

#include <iostream>
#include <cstdlib>

/* 
 * Use of C++11 variadic templates (functions) based on
 * http://oopscenities.net/2011/07/19/c0x-variadic-templates-functions/ 
 */ 
template <typename T>
__attribute__((noreturn)) void fatal_error (const T& message)
{
    std::cerr << message << std::endl;
    std::exit(1);
}

template <typename H, typename... T>
__attribute__((noreturn)) void fatal_error (const H& head, const T&... tail)
{
    std::cerr << head;
    fatal_error(tail...);
}

#endif