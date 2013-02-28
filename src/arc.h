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
        
        void add_line(Vector point, Vector vector);

        void add_arc(Vector center, Double radius, Double start_angle,
                     Double end_angle, Vector extrusion, Double thickness);

        void add_circle(Vector center, Double radius, Vector extrusion,
                        Double thickness);
        
        void add_ellipse(Vector center, Vector sm_axis, Double axis_ratio, 
                         Double start_angle, Double end_angle, 
                         Vector extrusion);
        
        void add_polyline(uint flags, Double const_width, Double elevation, 
                          Double thickness, Vector normal, std::vector<Vector> points,
                          std::vector<Double> bulges, std::vector<Interval> widths);
    private:
        void add_ellipse(Vector center, Vector a, Vector b);
    };
}

#endif