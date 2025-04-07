#include "parser.hpp"
#include "tasks.hpp"

#include <iostream>
#include <string_view>

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Please provide the task file as an argument\n";
    return 1;
  }

  const auto table = parser::load_from_file(argv[1]);

  tasks::run(table);

  return 0;
}
