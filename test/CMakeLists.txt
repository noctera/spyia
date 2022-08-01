add_executable(spyia-tests tests.cpp)

target_link_libraries(spyia-tests PRIVATE spyia gtest gtest_main gmock test-settings)

set_test_target_outputs(spyia-tests)