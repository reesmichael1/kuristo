add_executable(kuristo main.cpp tasks.cpp parser.cpp)

target_link_libraries(kuristo toml11::toml11 termcolor::termcolor)
