#ifndef __VECTOR_H_
#define __VECTOR_H_

#include "point.h"

class Vector : public Point
{
public:
    Vector(const Point&);
    Vector(const Double&, const Double&, const Double&);
};

#endif