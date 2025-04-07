#ifndef _PARSER_H_
#define _PARSER_H_

#include "tasks.hpp"

#include <string>

namespace parser {
TaskTable load_from_file(std::string_view);
}

#endif
