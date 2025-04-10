#ifndef PARSER_H
#define PARSER_H

#include "tasks.hpp"

#include <string>

namespace parser {
TaskTable load_from_file(std::string_view);
}

#endif
