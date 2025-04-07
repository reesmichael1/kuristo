cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
set(ProjectName "kuristo")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_LINKER_TYPE MOLD)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)

include(cmake/CPM.cmake)
CPMAddPackage("gh:ToruNiina/toml11@4.4.0")
CPMAddPackage("gh:ikalnytskyi/termcolor@2.1.0")

project(${ProjectName})

add_subdirectory(src)
