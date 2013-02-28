#include "vector.h"

#include <cmath>

Vector::Vector(const Point& p) : Point(p) { }

Vector::Vector(const Double& x, const Double& y) : Point(x, y, 0.0) { }

Vector::Vector(const Double& x, const Double& y, const Double& z) : Point(x, y, z) { }

Double Vector::norm() const 
{
    Double res = (_x*_x)+(_y*_y)+(_z*_z);

    return sqrt(res.value());
}

Vector Vector::cross_product(const Vector& b) const
{
    Double x = (_y * b.z()) - (_z * b.y());
    Double y = (_z * b.x()) - (_x * b.z());
    Double z = (_x * b.y()) - (_y * b.x());
    
    return Vector(x,y,z);
} 