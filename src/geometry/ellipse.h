#ifndef __ELLIPSE_H_
#define __ELLIPSE_H_

#include "../eltypes.h"

class Ellipse 
{
protected:
    Vector _center;
    Double _a,      // semi-major axis 
           _b,      // semi-minor axis
           _phi;    // rotation angle
    
public:
    Ellipse(Vector center, Double a, Double b);
    Ellipse(Vector center, Double a, Double b, Double phi);
    
    Vector get_center() const;
    void set_center(const Vector& center);
    
    Double get_a() const;
    void set_a(const Double& a);
    
    Double get_b() const;
    void set_b(const Double& b);
    
    Double get_phi() const;
    void set_phi(const Double& phi);
    
    Vector get_point(const Double& theta) const;
};

#endif