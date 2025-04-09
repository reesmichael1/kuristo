#include "parser.hpp"

#include "tasks.hpp"

#include <toml.hpp>

#include <string_view>

TaskTable parser::load_from_file(std::string_view path) {
  toml::color::enable();
  // It's annoying that toml::parse requires a string
  // Use a string_view here in the hopes this changes eventually
  const auto parsed{toml::parse(std::string{path})};

  const auto original_tasks = parsed.at("tasks").as_array();
  std::vector<Task> tasks;
  tasks.reserve(original_tasks.size());
  for (const auto &task : original_tasks) {
    std::vector<std::string> tags{};
    const auto original_tags = task.at("tags").as_array();
    tags.reserve(original_tags.size());
    for (const auto &tag : original_tags) {
      tags.push_back(tag.as_string());
    }

    std::istringstream iss(task.at("cmd").as_string());
    std::vector<std::string> cmd_words(std::istream_iterator<std::string>{iss},
                                       std::istream_iterator<std::string>());

    const auto cmd = cmd_words.at(0);
    cmd_words.erase(cmd_words.begin());

    tasks.push_back(Task{.name = task.at("name").as_string(),
                         .cmd = cmd,
                         .args = cmd_words,
                         .tags = tags});
  }

  TaskTable result{};
  result.description = parsed.at("description").as_string();
  result.tasks = tasks;
  return result;
}
