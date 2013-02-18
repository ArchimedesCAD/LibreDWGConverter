#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>

#include "c++11_warning.h"
#include "libredwg/src/dwg.h"

__attribute__((noreturn)) void fatal_error (const char* message)
{
    std::cerr << message << std::endl;
    std::exit(1);
}

inline void createArchimedesHeader(std::ostream& out)
{
    out << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" <<
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
        "</color>" << std::endl;
}

inline void finishArchimesFile(std::ostream& out)
{
    out << "</container></drawing>" << std::endl;
}

char *createOutputFileName(const char* filename)
{
  char *copy = strdup (filename);
  char *base = basename (copy);
  int len = strlen (base) + 5;
  char *rv = (char*)malloc (len);
  char *dot;

  if ((dot = strrchr (base, '.'))
      && dot + 4 < base + len
      && strncmp (1 + dot, "dwg", 3) == 0)
    *dot = '\0';
  snprintf (rv, len, "%s.arc", base);
  free (copy);
  return rv;
}

void add_line(double startX, double endX, double startY, double endY, std::ostream& out)
{
    out << "<line><point x=\"" << startX << "\" y=\"" << startY << "\" /><point x=\"" << endX << "\" y=\"" << endY << "\" /></line>";
}
  
int main(int argc, char* argv[])
{
    if (argc < 2)
        fatal_error("No input file specified");
    
    int error;
    Dwg_Data dwgData;
    error = dwg_read_file(argv[1], &dwgData);
    if (error) {
        /* This free can be refactored by using the deconstructor of a
         * object. This way we guarantee that the file is always freed */
        dwg_free(&dwgData);
        fatal_error("Can't open DWG file");
    }

    char *outputFileName = createOutputFileName(argv[1]);
    std::ofstream output(outputFileName);
    free(outputFileName);
    createArchimedesHeader(output);
    
    for (unsigned int i = 0; i < dwgData.num_objects; i++)
    {
        Dwg_Entity_LINE *line;

        switch (dwgData.object[i].type)
        {
        case DWG_TYPE_LINE:
            line = dwgData.object[i].tio.entity->tio.LINE;
            add_line(line->start.x, line->end.x, line->start.y, line->end.y, output);
            break;
        default:
            std::cerr << "Unsupported element found: "
                      << dwgData.object[i].type << std::endl;
        }
    }

    finishArchimesFile(output);
    output.close();
    dwg_free(&dwgData);
    return 0;
}
