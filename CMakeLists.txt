cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(CppSteg
	LANGUAGES CXX
	VERSION 1.1.0
)

# if(MSVC)
#  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zi")
#else()
#  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
#endif()
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

option(CPPSTEG_BUILD_EXAMPLES "Enables example building" ON)

add_library(${PROJECT_NAME} INTERFACE)

target_link_libraries( ${PROJECT_NAME} INTERFACE ${OpenCV_LIBS} )
target_include_directories(
	${PROJECT_NAME}
	INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(
	${PROJECT_NAME}
	INTERFACE
	cxx_std_17
)

if (CPPSTEG_BUILD_EXAMPLES)

	set(ExamplesDir "${CMAKE_CURRENT_SOURCE_DIR}/examples/")

	add_subdirectory(${ExamplesDir})

endif()
