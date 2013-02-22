#ifndef __BUILDER_H_
#define __BUILDER_H_

#include <fstream>

#include "eltypes.h"

namespace converter {
    class Builder 
    {  
    protected:
        std::fstream *out;
        char *filename;
        
        const Double EPSILON = 1e-16;
        const Double PI = 3.14159265358979323846;        

    public:
        Builder(const char*, const char*);
        virtual ~Builder();
        
        virtual void open_header() {}
        virtual void close_header() {}
        
        virtual void add_line_segment(Vector p1, Vector p2, Vector extrusion, 
                                      Double thickness) {}
        
        virtual void add_circle(Vector center, Double radius, Vector extrusion,
                                Double thickness) {};

        virtual void add_ellipse(Vector center, Vector sm_axis, Double axis_ratio, 
                                 Double start_angle, Double end_angle, 
                                 Vector extrusion) {}
    };
}

#endif