cmake_minimum_required(VERSION 3.21)

project(spyia VERSION 0.1.0)

if(PROJECT_IS_TOP_LEVEL)
    if(NOT "${CMAKE_CXX_STANDARD}")
        set(CMAKE_CXX_STANDARD 20)
    endif()
    set(CMAKE_CXX_EXTENSIONS OFF)

    if (NOT EXISTS ${CMAKE_BINARY_DIR}/CMakeCache.txt)
        if (NOT CMAKE_BUILD_TYPE)
            set(CMAKE_BUILD_TYPE "Release" CACHE STRING "" FORCE)
        endif()
    endif()
endif()

include (./cmake/warnings.cmake)
include (./cmake/example_target.cmake)
include (./cmake/options.cmake)

include (./cmake/fmt.cmake)

add_subdirectory(src/spyia)

if (${SPYIA_BUILD_EXAMPLES})
    add_subdirectory(examples)
endif()

if (${SPYIA_BUILD_TESTS})
    include(./cmake/test_target.cmake)
    include(./cmake/gtest.cmake)
    add_subdirectory(test)
endif()

if (${SPYIA_BUILD_DOCUMENTATION})
    add_subdirectory(docs_source)
endif()