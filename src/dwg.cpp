#include "dwg.h"

#include <iostream>

#include "util/util.h"
#include "util/error.h"


namespace converter {
    DWGReader::DWGReader(const char *urlfile) {
        int error = dwg_read_file(const_cast<char*>(urlfile), &dwg_data);
        
        if (error) {
            dwg_free(&dwg_data);
            fatal_error("Can't open file \"", urlfile, "\".");
        }
        
        url_wo_ext = util::get_url_without_ext(urlfile);
    }

    DWGReader::~DWGReader() {
        dwg_free(&dwg_data);
        free(url_wo_ext);
    }

    ulong DWGReader::get_num_objects() {
        return dwg_data.num_objects;
    }

    void DWGReader::convert_object(Builder *builder, ulong index) {
        switch(dwg_data.object[index].type) {
            case DWG_TYPE_LINE:
            {
                Dwg_Entity_LINE *line = dwg_data.object[index].tio.entity->tio.LINE;
                
                Vector p1        = {line->start.x, line->start.y, line->start.z};
                Vector p2        = {line->end.x, line->end.y, line->end.z};
                Vector extrusion = {line->extrusion.x, line->extrusion.y, 
                                    line->extrusion.z};
                Double thickness = line->thickness;
                
                builder->add_line_segment(p1,p2,extrusion,thickness);
                break;
            }            
            case DWG_TYPE_CIRCLE:
            {
                Dwg_Entity_CIRCLE *circle = 
                         dwg_data.object[index].tio.entity->tio.CIRCLE;
                
                Vector center    = {circle->center.x, circle->center.y, 
                                    circle->center.z};
                Double radius    = circle->radius;
                Vector extrusion = {circle->extrusion.x, circle->extrusion.y, 
                                    circle->extrusion.z};
                Double thickness = circle->thickness;
                
                builder->add_circle(center,radius,extrusion,thickness);
                break;
            }
            case DWG_TYPE_ELLIPSE:
            {
                Dwg_Entity_ELLIPSE *ellipse = 
                        dwg_data.object[index].tio.entity->tio.ELLIPSE;
                
                Vector center       = {ellipse->center.x, ellipse->center.y, 
                                       ellipse->center.z};
                Vector sm_axis      = {ellipse->sm_axis.x, ellipse->sm_axis.y,
                                       ellipse->sm_axis.z};
                Vector extrusion    = {ellipse->extrusion.x, ellipse->extrusion.y,
                                       ellipse->extrusion.z};
                Double axis_ratio   = ellipse->axis_ratio;
                Double start_angle  = ellipse->start_angle;
                Double end_angle    = ellipse->end_angle;
                
                builder->add_ellipse(center,sm_axis,axis_ratio,
                                     start_angle,end_angle,extrusion);
                break;
            }
            default:
                std::cerr << "Unsupported element found: "
                          << dwg_data.object[index].type << std::endl;
        }
    }

    const char* DWGReader::get_url_without_ext() {
        return (const char*)url_wo_ext;
    }
}