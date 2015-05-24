cmake_minimum_required(VERSION 3.0)
project(base)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -Werror -std=c99")

set(SOURCE_FILES src/main.c)
include_directories(/usr/include/glib-2.0)
include_directories(/usr/lib/x86_64-linux-gnu/glib-2.0/include)
link_libraries(glib-2.0)
add_executable(base ${SOURCE_FILES})