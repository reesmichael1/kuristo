#ifndef _TASK_TABLE_H_
#define _TASK_TABLE_H_

#include "task.hpp"

#include <memory>
#include <string>
#include <string_view>
#include <vector>

struct TaskTable {
  std::string description;
  std::vector<Task> tasks;
};

namespace tasks {
void run(const TaskTable &);
}

#endif
