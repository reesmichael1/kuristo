#ifndef _TASK_H_
#define _TASK_H_

#include <string>
#include <vector>

struct Task {
  std::string name;
  std::string cmd;
  std::vector<std::string> tags;
};

#endif
