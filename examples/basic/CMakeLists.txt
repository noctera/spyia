cmake_minimum_required(VERSION 3.21)

project(spyia-basic VERSION 0.1.0)
add_executable(spyia-basic main.cpp)

target_link_libraries(spyia-basic PRIVATE spyia)