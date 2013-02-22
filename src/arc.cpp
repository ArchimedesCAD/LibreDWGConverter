#include "arc.h"
#include "util/util.h"
#include "error.h"

using namespace std;

namespace converter {

    ARCBuilder::ARCBuilder(const char *name) : Builder(name, "arc") { }

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

    void ARCBuilder::add_line_segment(point p1, point p2) 
    {
         *out << "<line><point x=\"" << p1.x 
              << "\" y=\"" << p1.y 
              << "\" /><point x=\"" << p2.x 
              << "\" y=\"" << p2.y << "\" /></line>";
    }
    
    void ARCBuilder::add_circle(point center, ldouble radius)
    {
        *out << "<circle><point x=\"" << center.x 
             << "\" y = \"" << center.y << "\" />"
             << "<radius>" << radius << "</radius>"
             << "</circle>";             
    }
}