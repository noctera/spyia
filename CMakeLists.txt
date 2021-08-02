cmake_minimum_required(VERSION 3.19)
project(steganography)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(steganography)

add_compile_definitions(NCURSES_NOMACROS)

if(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zi")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
endif()

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
#set(BUILD_CPR_TESTS OFF) 
#include(FetchContent)


#FetchContent_Declare(opencv GIT_REPOSITORY https://github.com/opencv/opencv.git)
#FetchContent_MakeAvailable(opencv)

#target_link_libraries(steganography PRIVATE ${OpenCV_LIBS})

target_link_libraries( steganography ${OpenCV_LIBS} )

add_subdirectory(src)
add_subdirectory(include)