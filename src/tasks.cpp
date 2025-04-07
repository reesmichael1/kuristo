#include "tasks.hpp"

#include "task.hpp"
#include "tasks.hpp"

#include <termcolor/termcolor.hpp>
#include <toml.hpp>

#include <iostream>
#include <string_view>

void tasks::run(const TaskTable &table) {
  std::cout << table.description << "\n";

  for (const auto &task : table.tasks) {
    std::cout << termcolor::green << task.name << termcolor::reset << ": "
              << std::flush;
    std::system(task.cmd.c_str());
  }
}
