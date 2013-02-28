#include "double.h"

#include <limits>
#include <cmath>

Double::Double() : _x(0.0) { }

Double::Double(long double x) { _x = x; }

long double Double::value() const { return _x; }

void Double::set_value(long double x) { _x = x; }

bool Double::is_equal(const Double& d)
{
    return is_equal_with_epsilon(*this,d,std::numeric_limits<long double>::epsilon());
}

bool Double::is_equal_with_epsilon(const Double& d, const Double& epsilon) 
{
    return is_equal_with_epsilon(*this,d,epsilon);
}

bool Double::is_equal(const Double& d1, const Double& d2)
{
    return is_equal_with_epsilon(d1,d2,std::numeric_limits<long double>::epsilon());
}

bool Double::is_equal_with_epsilon(const Double& d1, const Double& d2, const Double& epsilon) 
{
    return fabs(d1.value()-d2.value()) <= epsilon.value();   
}

Double Double::operator-() const
{
     return (-_x);
}

Double operator+(const Double& x, const Double& y) 
{
     return x.value() + y.value();
}

Double operator-(const Double& x, const Double& y) 
{
     return x.value() - y.value();
}

Double operator*(const Double& x, const Double& y) 
{
     return x.value() * y.value();
}

Double operator/(const Double& x, const Double& y) 
{
     return x.value() / y.value();
}

std::istream& operator>> (std::istream &in, Double &d)
{
    in >> d._x;
    return in;
}

std::ostream& operator<<(std::ostream& os, const Double& d)
{
    os << d._x;
    return os;
}





