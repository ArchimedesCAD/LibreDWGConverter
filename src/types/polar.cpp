#include "polar.h"

#include <cmath>

#include "../util/constants.h"

Polar::Polar() : _radius(0.0), _angle(0.0) {}

Polar::Polar(const Point& p)
{
    _radius = sqrt((p.x()*p.x() + p.y()*p.y()).value());
    _angle  = p.angle();
} 

Polar::Polar(const Polar& polar) 
{
    _radius = polar.radius();
    _angle  = polar.angle();
}

Polar::Polar(const Double& radius, const Double& angle) 
{
    _radius = radius;
    _angle  = angle;
}
               
Double Polar::radius() const { return _radius; }

void Polar::set_radius(const Double& radius) { _radius = radius; }

Double Polar::angle() const { return _angle; }

void Polar::set_angle(const Double& angle) { _angle = angle; }

Point Polar::toCartesian() const 
{
    return Point(_radius*cos(_angle.value()), _radius*sin(_angle.value()), 0.0);
}