#ifndef __POLAR_H_
#define __POLAR_H_

#include "point.h"

class Polar
{
protected:
    Double _radius, _angle;
    
public:
    Polar();
    Polar(const Polar&);
    Polar(const Point&);
    Polar(const Double& polar, const Double& angle);
    
    Double radius() const;
    void set_radius(const Double&);
    
    Double angle() const;
    void set_angle(const Double&);
    
    Point toCartesian() const;
};

#endif 