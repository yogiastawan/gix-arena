cmake_minimum_required(VERSION 3.10.0)

add_executable(example example.c)
target_link_libraries(example gix-arena)