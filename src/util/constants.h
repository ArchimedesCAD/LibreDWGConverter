#ifndef __CONSTANTS_H_
#define __CONSTANTS_H_

#include <cmath>
#include <limits>

namespace constants {
    static constexpr long double PI         = std::atan(1.0)*4;
    static const long double     EPSILON    = 1e-16;
    static constexpr int         PRECISION  = std::numeric_limits<long double>::digits10;
}

#endif