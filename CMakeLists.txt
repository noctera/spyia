cmake_minimum_required(VERSION 3.18 FATAL_ERROR)


set(CPM_DOWNLOAD_VERSION 0.32.0)

if(CPM_SOURCE_CACHE)
  set(CPM_DOWNLOAD_LOCATION "${CPM_SOURCE_CACHE}/cpm/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
elseif(DEFINED ENV{CPM_SOURCE_CACHE})
  set(CPM_DOWNLOAD_LOCATION "$ENV{CPM_SOURCE_CACHE}/cpm/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
else()
  set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
endif()

if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
  message(STATUS "Downloading CPM.cmake to ${CPM_DOWNLOAD_LOCATION}")
  file(DOWNLOAD
       https://github.com/TheLartians/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake
       ${CPM_DOWNLOAD_LOCATION}
  )
endif()

include(${CPM_DOWNLOAD_LOCATION})

project(CppSteg
	LANGUAGES CXX
	VERSION 0.0.1
)

find_package( OpenCV REQUIRED )
include(CTest)

option(CPPSTEG_BUILD_EXAMPLES "Enables example building" ON)
option(CPPSTEG_BUILD_TESTS "Enables tests building" ON)

add_library(${PROJECT_NAME} INTERFACE)

target_link_libraries(${PROJECT_NAME} INTERFACE 
	opencv_core
	opencv_imgproc
	opencv_imgcodecs
	)

target_include_directories(
	${PROJECT_NAME}
	INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(
	${PROJECT_NAME}
	INTERFACE
	cxx_std_11
)

if (CPPSTEG_BUILD_EXAMPLES)
	set(ExamplesDir "${CMAKE_CURRENT_SOURCE_DIR}/examples/")
	add_subdirectory(${ExamplesDir})
endif()

if (CPPSTEG_BUILD_TESTS)
	set(TestsDir "${CMAKE_CURRENT_SOURCE_DIR}/tests/")
	add_subdirectory(${TestsDir})
endif()


