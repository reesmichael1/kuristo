#include "tasks.hpp"

#include "task.hpp"
#include "tasks.hpp"

#include <boost/asio.hpp>
#include <boost/asio/readable_pipe.hpp>
#include <boost/process/v2/process.hpp>
#include <boost/process/v2/stdio.hpp>
#include <termcolor/termcolor.hpp>
#include <toml.hpp>

#include <iostream>
#include <string_view>

namespace bp = boost::process::v2;

bool is_builtin(std::string name) {
  boost::asio::io_context ctx{};
  bp::process proc{
      ctx,
      "/usr/bin/sh",
      {"-c", "type " + name},
      bp::process_stdio{.in = stdout, .out = nullptr, .err = nullptr},
  };
  const int status = proc.wait();
  return status == 0;
}

void tasks::run(const TaskTable &table) {
  std::cout << table.description << "\n";

  for (const auto &task : table.tasks) {
    boost::asio::io_context ctx;
    boost::asio::readable_pipe rp{ctx};

    if (is_builtin(task.cmd)) {
      std::stringstream ss;
      for (size_t i = 0; i < task.args.size(); ++i) {
        if (i != 0) {
          ss << " ";
        }

        ss << task.args.at(i);
      }
      bp::process proc(ctx, "/usr/bin/sh", {"-c", task.cmd + " " + ss.str()},
                       bp::process_stdio{.in = {}, .out = rp, .err = {}});
      proc.wait();

      std::string output{};
      boost::system::error_code ec;
      boost::asio::read(rp, boost::asio::dynamic_buffer(output), ec);
      std::cout << termcolor::green << task.name << termcolor::reset << ": "
                << output << std::endl;
    } else {
      bp::process proc{ctx, task.cmd, task.args};
      proc.wait();
    }
  }
}
