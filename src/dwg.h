#ifndef __DWG_H_
#define __DWG_H_

#include "../libredwg/src/dwg.h"

#include "builder.h"

namespace converter {
    class DWGReader 
    {
        Dwg_Data dwg_data;
        char *url_wo_ext;

    public:
        DWGReader(const char *filename);
        ~DWGReader();

        ulong get_num_objects();
        void convert_object(Builder*,ulong);
        
        const char* get_url_without_ext();
    };
}

#endif