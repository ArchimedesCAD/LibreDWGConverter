#include "point.h"

#include <cmath>

Point::Point(const Point& p) : _x(p.x()), _y(p.y()), _z(p.z()) { }

Point::Point(const Double& x, const Double& y) : _x(x), _y(y), _z(0.0) {}
                
Point::Point(const Double& x, const Double& y, const Double& z) : 
                _x(x), _y(y), _z(z) {}

Double Point::x() const { return _x; }

void Point::set_x(const Double& x) { _x = x; }

Double Point::y() const { return _y; }

void Point::set_y(const Double& y) { _y = y; }

Double Point::z() const { return _z; }

void Point::set_z(const Double& z) { _z = z; }

Point Point::operator+( const Point &p ) const
{
    return Point(_x + p.x(), _y + p.y(), _z + p.z());
}

Point Point::operator-( const Point &p ) const
{
    return Point(_x - p.x(), _y - p.y(), _z - p.z());
}

Point Point::operator*( const Double &d ) const
{
    return Point(_x * d, _y * d, _z * d);
}

bool Point::is_equal(const Point& p)
{
    return is_equal(*this, p);
}

bool Point::is_equal(const Point& p, const Double& d)
{
    return is_equal(*this, p, d);
}

bool Point::is_equal(const Point& p1, const Point& p2) 
{
    return (p1.x().is_equal(p2.x()) &&
            p1.y().is_equal(p2.y()) &&
            p1.z().is_equal(p2.z()));
}

bool Point::is_equal(const Point& p1, const Point& p2, const Double& epsilon) 
{
    return (p1.x().is_equal_with_epsilon(p2.x(), epsilon) &&
            p1.y().is_equal_with_epsilon(p2.y(), epsilon) &&
            p1.z().is_equal_with_epsilon(p2.z(), epsilon));
}

Double Point::distance(const Point& p) const 
{
    return distance(*this,p);
}

Double Point::distance(const Point& p1, const Point& p2)
{
    Double res = ((p1.x()-p2.x())*(p1.x()-p2.x())) +
                 ((p1.y()-p2.y())*(p1.y()-p2.y())) +
                 ((p1.z()-p2.z())*(p1.z()-p2.z()));
    
    return sqrt(res.value());
}

std::ostream& operator<<(std::ostream& os, const Point& p)
{
    os << "(" << p._x << "," << p._y << "," << p._z << ")";
    return os;
}

Point operator*(const Double &d, const Point &p)
{
    return Point(p._x * d, p._y * d, p._z * d);
}