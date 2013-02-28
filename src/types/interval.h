#ifndef __INTERVAL_H_
#define __INTERVAL_H_

#include "double.h"

class Interval
{
protected:
    Double _start, _end;

public:
    Interval() { };
    Interval(const Double& start, const Double& end);
    
    Double start() const;
    void set_start(const Double&);
    
    Double end() const;
    void set_end(const Double&);
};

#endif