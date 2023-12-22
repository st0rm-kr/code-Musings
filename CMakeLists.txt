cmake_minimum_required(VERSION 3.1)

project(code-musings)

set(CMAKE_CXX_STANDARD 17)

include_directories(third-party/google-test)

add_subdirectory(src)
