add_library(spyia STATIC
    test.cpp
)

target_include_directories(spyia PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include)
target_link_libraries(spyia PUBLIC fmt::fmt)

set_target_warnings(spyia)

set_target_outputs(spyia)