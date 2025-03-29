add_executable(kuristo main.cpp tasks.cpp)

target_link_libraries(kuristo toml11::toml11)
