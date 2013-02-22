#ifndef __POINT_H_
#define __POINT_H_

#include <iostream>

#include "double.h"

class Point
{
protected:
    Double _x, _y, _z;
    
public:
    Point(const Point&);
    Point(const Double&, const Double&, const Double&);
    
    Double x() const;
    void set_x(const Double&);
    
    Double y() const;
    void set_y(const Double&);
    
    Double z() const;
    void set_z(const Double&);
    
    Point operator+(const Point&) const; 
    Point operator-(const Point&) const;
    Point operator*(const Double&) const;
    
    bool is_equal(const Point& p);
    bool is_equal(const Point& p, const Double& epsilon);
    static bool is_equal(const Point& p1, const Point& p2);
    static bool is_equal(const Point& p1, const Point& p2, const Double& epsilon);
    
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

std::ostream& operator<<(std::ostream& os, const Point& p);

#endif