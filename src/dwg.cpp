#include "dwg.h"

#include <iostream>

#include "util/util.h"
#include "util/error.h"

#define APPOINT_ENUM_MAP(enum,map) map[enum] = #enum

namespace converter {
    void DWGReader::success(Dwg_Object_Type type) 
    {
        std::cerr << "Converted element: " << names[type] << std::endl;
    }
    
    void DWGReader::fail(Dwg_Object_Type type)
    {
        std::string name = names[type];
        
        std::cerr << "Unsupported element found: ";
        if (name.size() > 0) {
            std::cerr << name << std::endl;
        } else {
            std::cerr << "0x" << std::hex << type << std::endl;
        }
    }
    
    DWGReader::DWGReader(const char *urlfile) {
        int error = dwg_read_file(const_cast<char*>(urlfile), &dwg_data);
        
        if (error) {
            dwg_free(&dwg_data);
            fatal_error("Can't open file \"", urlfile, "\".");
        }
        
        url_wo_ext = util::get_url_without_ext(urlfile);
                
        APPOINT_ENUM_MAP(DWG_TYPE_UNUSED                , names);
        APPOINT_ENUM_MAP(DWG_TYPE_TEXT                  , names);
        APPOINT_ENUM_MAP(DWG_TYPE_ATTRIB                , names);
        APPOINT_ENUM_MAP(DWG_TYPE_ATTDEF                , names);
        APPOINT_ENUM_MAP(DWG_TYPE_BLOCK                 , names);
        APPOINT_ENUM_MAP(DWG_TYPE_ENDBLK                , names);
        APPOINT_ENUM_MAP(DWG_TYPE_SEQEND                , names);
        APPOINT_ENUM_MAP(DWG_TYPE_INSERT                , names);
        APPOINT_ENUM_MAP(DWG_TYPE_MINSERT               , names);
        //APPOINT_ENUM_MAP(DWG_TYPE_<UNKNOWN> = 0x09    , names);
        APPOINT_ENUM_MAP(DWG_TYPE_VERTEX_2D             , names);
        APPOINT_ENUM_MAP(DWG_TYPE_VERTEX_3D             , names);
        APPOINT_ENUM_MAP(DWG_TYPE_VERTEX_MESH           , names);
        APPOINT_ENUM_MAP(DWG_TYPE_VERTEX_PFACE          , names);
        APPOINT_ENUM_MAP(DWG_TYPE_VERTEX_PFACE_FACE     , names);
        APPOINT_ENUM_MAP(DWG_TYPE_POLYLINE_2D           , names);
        APPOINT_ENUM_MAP(DWG_TYPE_POLYLINE_3D           , names);
        APPOINT_ENUM_MAP(DWG_TYPE_ARC                   , names);
        APPOINT_ENUM_MAP(DWG_TYPE_CIRCLE                , names);
        APPOINT_ENUM_MAP(DWG_TYPE_LINE                  , names);
        APPOINT_ENUM_MAP(DWG_TYPE_DIMENSION_ORDINATE    , names);
        APPOINT_ENUM_MAP(DWG_TYPE_DIMENSION_LINEAR      , names);
        APPOINT_ENUM_MAP(DWG_TYPE_DIMENSION_ALIGNED     , names);
        APPOINT_ENUM_MAP(DWG_TYPE_DIMENSION_ANG3PT      , names);
        APPOINT_ENUM_MAP(DWG_TYPE_DIMENSION_ANG2LN      , names);
        APPOINT_ENUM_MAP(DWG_TYPE_DIMENSION_RADIUS      , names);
        APPOINT_ENUM_MAP(DWG_TYPE_DIMENSION_DIAMETER    , names);
        APPOINT_ENUM_MAP(DWG_TYPE_POINT                 , names);
        APPOINT_ENUM_MAP(DWG_TYPE__3DFACE               , names);
        APPOINT_ENUM_MAP(DWG_TYPE_POLYLINE_PFACE        , names);
        APPOINT_ENUM_MAP(DWG_TYPE_POLYLINE_MESH         , names);
        APPOINT_ENUM_MAP(DWG_TYPE_SOLID                 , names);
        APPOINT_ENUM_MAP(DWG_TYPE_TRACE                 , names);
        APPOINT_ENUM_MAP(DWG_TYPE_SHAPE                 , names);
        APPOINT_ENUM_MAP(DWG_TYPE_VIEWPORT              , names);
        APPOINT_ENUM_MAP(DWG_TYPE_ELLIPSE               , names);
        APPOINT_ENUM_MAP(DWG_TYPE_SPLINE                , names);
        APPOINT_ENUM_MAP(DWG_TYPE_REGION                , names);
        APPOINT_ENUM_MAP(DWG_TYPE_3DSOLID               , names);
        APPOINT_ENUM_MAP(DWG_TYPE_BODY                  , names);
        APPOINT_ENUM_MAP(DWG_TYPE_RAY                   , names);
        APPOINT_ENUM_MAP(DWG_TYPE_XLINE                 , names);
        APPOINT_ENUM_MAP(DWG_TYPE_DICTIONARY            , names);
        //APPOINT_ENUM_MAP(DWG_TYPE_<UNKNOWN>           , names);
        APPOINT_ENUM_MAP(DWG_TYPE_MTEXT                 , names);
        APPOINT_ENUM_MAP(DWG_TYPE_LEADER                , names);
        APPOINT_ENUM_MAP(DWG_TYPE_TOLERANCE             , names);
        APPOINT_ENUM_MAP(DWG_TYPE_MLINE                 , names);
        APPOINT_ENUM_MAP(DWG_TYPE_BLOCK_CONTROL         , names);
        APPOINT_ENUM_MAP(DWG_TYPE_BLOCK_HEADER          , names);
        APPOINT_ENUM_MAP(DWG_TYPE_LAYER_CONTROL         , names);
        APPOINT_ENUM_MAP(DWG_TYPE_LAYER                 , names);
        APPOINT_ENUM_MAP(DWG_TYPE_SHAPEFILE_CONTROL     , names);
        APPOINT_ENUM_MAP(DWG_TYPE_SHAPEFILE             , names);
        //APPOINT_ENUM_MAP(DWG_TYPE_<UNKNOWN>           , names);
        //APPOINT_ENUM_MAP(DWG_TYPE_<UNKNOWN>           , names);
        APPOINT_ENUM_MAP(DWG_TYPE_LTYPE_CONTROL         , names);
        APPOINT_ENUM_MAP(DWG_TYPE_LTYPE                 , names);
        //APPOINT_ENUM_MAP(DWG_TYPE_<UNKNOWN>           , names);
        //APPOINT_ENUM_MAP(DWG_TYPE_<UNKNOWN>           , names);
        APPOINT_ENUM_MAP(DWG_TYPE_VIEW_CONTROL          , names);
        APPOINT_ENUM_MAP(DWG_TYPE_VIEW                  , names);
        APPOINT_ENUM_MAP(DWG_TYPE_UCS_CONTROL           , names);
        APPOINT_ENUM_MAP(DWG_TYPE_UCS                   , names);
        APPOINT_ENUM_MAP(DWG_TYPE_VPORT_CONTROL         , names);
        APPOINT_ENUM_MAP(DWG_TYPE_VPORT                 , names);
        APPOINT_ENUM_MAP(DWG_TYPE_APPID_CONTROL         , names);
        APPOINT_ENUM_MAP(DWG_TYPE_APPID                 , names);
        APPOINT_ENUM_MAP(DWG_TYPE_DIMSTYLE_CONTROL      , names);
        APPOINT_ENUM_MAP(DWG_TYPE_DIMSTYLE              , names);
        APPOINT_ENUM_MAP(DWG_TYPE_VP_ENT_HDR_CONTROL    , names);
        APPOINT_ENUM_MAP(DWG_TYPE_VP_ENT_HDR            , names);
        APPOINT_ENUM_MAP(DWG_TYPE_GROUP                 , names);
        APPOINT_ENUM_MAP(DWG_TYPE_MLINESTYLE            , names);
        //APPOINT_ENUM_MAP(DWG_TYPE_<UNKNOWN>           , names);
        //APPOINT_ENUM_MAP(DWG_TYPE_<UNKNOWN>           , names);
        //APPOINT_ENUM_MAP(DWG_TYPE_<UNKNOWN>           , names);
        APPOINT_ENUM_MAP(DWG_TYPE_LWPLINE               , names);
        APPOINT_ENUM_MAP(DWG_TYPE_HATCH                 , names);
        APPOINT_ENUM_MAP(DWG_TYPE_XRECORD               , names);
        APPOINT_ENUM_MAP(DWG_TYPE_PLACEHOLDER           , names);
        //APPOINT_ENUM_MAP(DWG_TYPE_<UNKNOWN>           , names);
        APPOINT_ENUM_MAP(DWG_TYPE_LAYOUT                , names);
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
            case DWG_TYPE_XLINE:
            {
                Dwg_Entity_XLINE *xline = dwg_data.object[index].tio.entity->tio.XLINE;
                
                Vector point  = {xline->point.x, xline->point.y, xline->point.z};
                Vector vector = {xline->vector.x, xline->vector.y, xline->vector.z};
                
                builder->add_line(point,vector);
                
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
            {
                fail(static_cast<Dwg_Object_Type>(dwg_data.object[index].type));
                return;
            }
        }
        
        success(static_cast<Dwg_Object_Type>(dwg_data.object[index].type));
    }

    const char* DWGReader::get_url_without_ext() {
        return (const char*)url_wo_ext;
    }
}