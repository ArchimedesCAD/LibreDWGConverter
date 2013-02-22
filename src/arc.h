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
        
        void add_line_segment(Vector p1, Vector p2, Vector extrusion, 
                              Double thickness);

        void add_circle(Vector center, Double radius, Vector extrusion,
                        Double thickness);
        
        void add_ellipse(Vector center, Vector sm_axis, Double axis_ratio, 
                         Double start_angle, Double end_angle, 
                         Vector extrusion);
        
    private:
        void add_ellipse(Vector center, Vector a, Vector b);
    };
}

#endif