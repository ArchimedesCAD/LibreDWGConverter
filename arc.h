#ifndef __ARC_H_
#define __ARC_H_

#include "eltypes.h"
#include "builder.h"

namespace converter {
    class ARCBuilder : public Builder 
    {        
    public:
        ARCBuilder(const char *filename);
        ~ARCBuilder();
        
        void open_header();
        void close_header();
        
        void add_line_segment(point, point);
    };
}

#endif