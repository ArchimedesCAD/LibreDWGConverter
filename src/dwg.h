#ifndef __DWG_H_
#define __DWG_H_

#include <map>

#include "../libredwg/src/dwg.h"
#include "builder.h"

namespace converter {
    class DWGReader 
    {
        Dwg_Data dwg_data;
        char *url_wo_ext;
        std::map<DWG_OBJECT_TYPE,std::string> names;
        
        void success(Dwg_Object_Type type);
        void fail(Dwg_Object_Type type);
        
    public:
        DWGReader(const char *filename);
        ~DWGReader();

        ulong get_num_objects();
        void convert_object(Builder*,ulong);
        
        const char* get_url_without_ext();
    };
}

#endif