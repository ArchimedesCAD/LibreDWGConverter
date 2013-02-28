#include "interval.h"

Interval::Interval(const Double& start, const Double& end) 
{
    _start = start;
    _end   = end;
}

Double Interval::start() const { return _start; }

void Interval::set_start(const Double& start) { _start = start; }

Double Interval::end() const { return _end; }

void Interval::set_end(const Double& end) { _end = end; }