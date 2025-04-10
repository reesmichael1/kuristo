#ifndef TASK_H
#define TASK_H

#include <string>
#include <vector>

struct Task {
  std::string name;
  std::string cmd;
  std::vector<std::string> args;
  std::vector<std::string> tags;
};

#endif
