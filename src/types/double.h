#ifndef __DOUBLE_H_
#define __DOUBLE_H_

#include <iostream>

class Double
{
    long double _x;
    
public:
    Double();
    Double(long double x);

    long double value() const;
    void set_value(long double);

    bool is_equal(const Double&);
    bool is_equal_with_epsilon(const Double& d, const Double& epsilon);
    
    static bool is_equal(const Double&, const Double&);
    static bool is_equal_with_epsilon(const Double& d1, const Double& d2, const Double& epsilon);
    
    Double operator-() const;
    
    friend Double operator+(const Double&, const Double&);
    friend Double operator-(const Double&, const Double&);
    friend Double operator*(const Double&, const Double&);
    friend Double operator/(const Double&, const Double&);
    
    friend std::istream& operator>>(std::istream& in, Double& d);
    friend std::ostream& operator<<(std::ostream& os, const Double& d);
};

Double operator+(const Double&, const Double&);
Double operator-(const Double&, const Double&);
Double operator*(const Double&, const Double&);
Double operator/(const Double&, const Double&);
    
std::istream& operator>>(std::istream& in, Double& d);
std::ostream& operator<<(std::ostream& os, const Double& d);

#endif