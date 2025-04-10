add_executable(kuristo main.cpp tasks.cpp parser.cpp)

target_compile_options(kuristo PUBLIC -Wall -Wextra -Wpedantic -Werror)
target_link_libraries(kuristo toml11::toml11 termcolor::termcolor Boost::process Boost::thread)
