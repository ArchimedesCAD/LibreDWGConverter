#include <cstring>
#include <cstdlib>

#include "util.h"

namespace util {
    char* create_filename(const char* filename, const char* ext)
    {
        char *res = (char*)malloc(strlen(filename)+strlen(ext)+5);
      
        res[0] = '\0';
        strcat(res,filename);
        strcat(res,".");
        strcat(res,ext);
      
        return res;
    }

    char* get_url_without_ext(const char* filename) 
    {
        char *res = (char*)malloc(strlen(filename));
        const char *dot = strrchr(filename, '.');
        
        strncpy(res,filename,dot-filename);
        res[dot-filename] = '\0';
        
        return res;
    }
}