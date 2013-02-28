#include "arc.h"

#include "util/util.h"
#include "util/error.h"
#include "util/constants.h"

#include "geometry/ellipse.h"

using namespace std;

namespace converter {

    ARCBuilder::ARCBuilder(const char *name) : Builder(name, "arc") 
    {
        out->precision(constants::PRECISION);
    }

    ARCBuilder::~ARCBuilder() { }

    void ARCBuilder::open_header() 
    {
        *out << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" <<
           "<drawing xmlns=\"http://www.archimedes.org.br/xml/FileXMLSchema\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:schemaLocation=\"http://www.archimedes.org.br/xml/FileXMLSchema FileXMLSchema.xsd\">" <<
           "<zoom>1.0</zoom>" <<
           "<viewport><point x=\"0.0\" y=\"0.0\" /></viewport>" <<
           "<container name=\"Camada\" lineStyle=\"0\" thickness=\"1.0\" visible=\"true\" locked=\"false\" >" <<
            "<color>"<<
           "<unsignedByte>255</unsignedByte>"<<
           "<unsignedByte>255</unsignedByte>"<<
           "<unsignedByte>255</unsignedByte>"<<
           "</color>"<<
           "<color>"<<
           "<unsignedByte>0</unsignedByte>"<<
           "<unsignedByte>0</unsignedByte>"<<
           "<unsignedByte>0</unsignedByte>"<<
           "</color>" << endl;
    }

    void ARCBuilder::close_header() 
    {
        *out << "</container></drawing>" << endl;
    }

    void ARCBuilder::add_line_segment(Vector p1, Vector p2, Vector extrusion,
                                      Double thickness)
    {
         *out << "<line>"
              << "<point x=\"" << p1.x() << "\" y=\"" << p1.y() << "\" />"
              << "<point x=\"" << p2.x() << "\" y=\"" << p2.y() << "\" />"
              << "</line>";
    }
    
    void ARCBuilder::add_line(Vector point, Vector vector)
    {
        Point point2 = point + 10*vector;
        
        *out << "<infiniteline>"
             << "<point x=\"" << point.x() << "\" y=\"" << point.y() << "\" />"
             << "<point x=\"" << point2.x() << "\" y=\"" << point2.y() << "\" />"
             << "</infiniteline>";
    }
    
    void ARCBuilder::add_arc(Vector center, Double radius, Double start_angle,
                             Double end_angle, Vector extrusion, Double thickness)
    {
        Polar polar1(radius, start_angle);
        Polar polar2(radius, (start_angle+end_angle)/2);
        Polar polar3(radius, end_angle);
        
        if (start_angle.value() > end_angle.value()) {
            polar2.set_angle(polar2.angle() + constants::PI);
        }
        
        Vector p1 = polar1.toCartesian() + center;
        Vector p2 = polar2.toCartesian() + center;
        Vector p3 = polar3.toCartesian() + center;
        
        *out << "<arc>"
             << "<point x=\"" << p1.x() << "\" y=\"" << p1.y() << "\" />"
             << "<point x=\"" << p2.x() << "\" y=\"" << p2.y() << "\" />"
             << "<point x=\"" << p3.x() << "\" y=\"" << p3.y() << "\" />"
             << "</arc>";
    }

    void ARCBuilder::add_circle(Vector center, Double radius, Vector extrusion,
                                Double thickness)
    {
        *out << "<circle>"
             << "<point x=\"" << center.x() << "\" y =\"" << center.y() << "\" />"
             << "<radius>" << radius << "</radius>"
             << "</circle>";             
    }
    
    void ARCBuilder::add_ellipse(Vector center, Vector sm_axis, Double axis_ratio, 
                                 Double start_angle, Double end_angle, 
                                 Vector extrusion)
    {
        Vector a = center - sm_axis;
        Vector b = center - 
                   (Vector(-a.y()+center.y(),a.x()-center.x(), 0.0)*axis_ratio); // Only 2D
            
        if (start_angle.is_equal_with_epsilon(0.0, constants::EPSILON) &&
            end_angle.is_equal_with_epsilon(2*constants::PI, constants::EPSILON)) {
            add_ellipse(center, a, b);
        } else {
            Double dist_a = a.distance(center);
            Double dist_b = b.distance(center);
            Double phi    = (a-center).angle();
            
            Ellipse ellipse(center, dist_a, dist_b, phi);
            
            add_ellipse(center, a, b, ellipse.get_point(start_angle), 
                        ellipse.get_point(end_angle));                      
        }
    }
    
    void ARCBuilder::add_polyline(uint flags, Double const_width, Double elevation, 
                                  Double thickness, Vector normal, std::vector<Vector> points,
                                  std::vector<Double> bulges, std::vector<Interval> widths)
    {
        *out << "<polyline>";
        
        for (auto &p : points) {
             *out << "<point x=\"" << p.x() << "\" y=\"" << p.y() << "\"/>";
        }
        
        /*
         *  Observation of Neuton Jr: i suspect when flag be equals zero indicates opened 
         * polylines. Otherwise, flag indicates polygons.
         */
        if (points.size() > 2 && flags) {
            Vector p = points[0];
            *out << "<point x=\"" << p.x() << "\" y=\"" << p.y() << "\"/>";
        }
        
        *out << "</polyline>";
    }
    
    void ARCBuilder::add_ellipse(Vector center, Vector a, Vector b)
    {
        *out << "<ellipse>"
             << "<point x=\"" << center.x() << "\" y=\"" << center.y() << "\"/>"
             << "<point x=\"" << a.x() << "\" y=\"" << a.y() << "\"/>"
             << "<point x=\"" << b.x() << "\" y=\"" << b.y() << "\"/>"
             << "</ellipse>";
    }
       
    void ARCBuilder::add_ellipse(Vector center, Vector a, Vector b, 
                                 Vector start_point, Vector end_point)
    {
        *out << "<ellipse>"
             << "<point x=\"" << center.x() << "\" y=\"" << center.y() << "\"/>"
             << "<point x=\"" << a.x() << "\" y=\"" << a.y() << "\"/>"
             << "<point x=\"" << b.x() << "\" y=\"" << b.y() << "\"/>"
             << "<point x=\"" << start_point.x() << "\" y=\"" << start_point.y() << "\"/>"
             << "<point x=\"" << end_point.x() << "\" y=\"" << end_point.y() << "\"/>"
             << "</ellipse>";
    }
}