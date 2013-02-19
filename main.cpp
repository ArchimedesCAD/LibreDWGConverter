#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>

#include "c++11_warning.h"
#include "arc.h"
#include "dwg.h"
#include "error.h"

using namespace std;
using namespace converter;

int main(int argc, char* argv[])
{
    if (argc < 2)
        fatal_error("No input file specified");
    
    DWGReader *dwg = new DWGReader(argv[1]);
    ARCBuilder *arc = new ARCBuilder(dwg->get_url_without_ext());
    
    arc->open_header();
    
    for (ulong i = 0; i < dwg->get_num_objects(); i++) {        
        dwg->convert_object(arc, i);
    }

    arc->close_header();
    
    delete arc;
    delete dwg;
    
    return 0;
}