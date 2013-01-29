#include <cstdlib>
#include <iostream>
extern "C" {
#include <dwg.h>
}

#include "c++11_warning.h"

__attribute__((noreturn)) void fatal_error (const char* message)
{
    std::cerr << message << std::endl;
    std::exit(1);
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
    
    dwg_free(&dwgData);
    return 0;
}
