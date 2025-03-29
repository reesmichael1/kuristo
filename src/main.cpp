#include "tasks.hpp"

#include <iostream>
#include <string_view>

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Please provide the task file as an argument\n";
    return 1;
  }

  const auto table = tasks::load_from_file(argv[1]);
  std::cout << table.description << "\n";

  for (const auto &task : table.tasks) {
    std::cout << task.name << "\n";
  }

  return 0;
}
