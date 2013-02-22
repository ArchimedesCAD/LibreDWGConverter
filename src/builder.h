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
        
    public:
        Builder(const char*, const char*);
        virtual ~Builder();
        
        virtual void open_header() {}
        virtual void close_header() {}
        
        virtual void add_line_segment(Point p1, Point p2, Vector extrusion, 
                                      Double thickness) {}
        
        virtual void add_circle(Point center, Double radius, Vector extrusion,
                                Double thickness) {}
    };
}

#endif