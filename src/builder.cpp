#include "builder.h"

#include <iostream>

#include "util/error.h"
#include "util/util.h"

namespace converter {
    Builder::Builder(const char *url_wo_ext, const char *ext) 
    {
        filename = util::create_filename(url_wo_ext,ext);
        
        std::cout << "Creating file \"" << filename << "\"...";
        out = new std::fstream(filename, std::fstream::out);
        
        if (out->fail()) {
            fatal_error("ERROR: Can't create file: ", filename);
        } else {
            std::cout << "OK" << std::endl;
        }
    }

    Builder::~Builder() 
    {
        std::cout << "Closing file \"" << filename << "\"...OK" << std::endl;
        
        free(filename);
        out->close();
        delete out;
    }
}