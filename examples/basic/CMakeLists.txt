add_executable(basic main.cpp)

target_link_libraries(basic PRIVATE spyia)

set_target_outputs(basic)