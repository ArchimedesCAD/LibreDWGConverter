#include "ellipse.h"

#include <cmath>

Ellipse::Ellipse(Vector center, Double a, Double b)
{
    _center = center;
    _a = a;
    _b = b;
    _phi = 0.0;
} 

Ellipse::Ellipse(Vector center, Double a, Double b, Double phi) 
{
    _center = center;
    _a = a;
    _b = b;
    _phi = phi;    
}
    
Vector Ellipse::get_center() const { return _center; }
 
void Ellipse::set_center(const Vector& center) { _center = center; }
    
Double Ellipse::get_a() const { return _a; }

void Ellipse::set_a(const Double& a) { _a = a; }

Double Ellipse::get_b() const { return _b; }

void Ellipse::set_b(const Double& b) { _b = b; }
    
Double Ellipse::get_phi() const { return _phi; }

void Ellipse::set_phi(const Double& phi) { _phi = phi; }

Vector Ellipse::get_point(const Double& theta) const
{
    Double x = _center.x() + (_a*cos(theta.value())*cos(_phi.value()))
                           - (_b*sin(theta.value())*sin(_phi.value()));
    Double y = _center.y() + (_a*cos(theta.value())*sin(_phi.value()))
                           + (_b*sin(theta.value())*cos(_phi.value()));
    
    return Vector(x,y);
}