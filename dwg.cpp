#include "dwg.h"
#include "util.h"
#include "error.h"

namespace converter {
    DWGReader::DWGReader(const char *urlfile) {
        int error = dwg_read_file(const_cast<char*>(urlfile), &dwg_data);
        
        if (error) {
            dwg_free(&dwg_data);
            fatal_error("Can't open file \"", urlfile, "\".");
        }
        
        url_wo_ext = util::get_url_without_ext(urlfile);
    }

    DWGReader::~DWGReader() {
        dwg_free(&dwg_data);
        free(url_wo_ext);
    }

    ulong DWGReader::get_num_objects() {
        return dwg_data.num_objects;
    }

    void DWGReader::convert_object(Builder *builder, ulong index) {
        switch(dwg_data.object[index].type) {
            case DWG_TYPE_LINE:
            {
                Dwg_Entity_LINE *line = dwg_data.object[index].tio.entity->tio.LINE;
                point p1 = {line->start.x, line->start.y, line->start.z};
                point p2 = {line->end.x, line->end.y, line->end.z};
                builder->add_line_segment(p1,p2);
                break;
            }
            default:
                std::cerr << "Unsupported element found: "
                          << dwg_data.object[index].type << std::endl;
        }
    }

    const char* DWGReader::get_url_without_ext() {
        return (const char*)url_wo_ext;
    }
}