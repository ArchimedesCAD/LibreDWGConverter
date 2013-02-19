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
        ~Builder();
        
        virtual void open_header() = 0;
        virtual void close_header() = 0;
        
        virtual void add_line_segment(point p1, point p2) = 0;
    };
}

#endif