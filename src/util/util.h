#ifndef __UTILS_H_
#define __UTILS_H_

namespace util {
    char* create_filename(const char* filename, const char* ext);
    char* get_url_without_ext(const char* filename);
}

#endif