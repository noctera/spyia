cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

project(cppsteg_tests)

include(FetchContent)

CPMAddPackage("gh:catchorg/Catch2@2.5.0")
FetchContent_Declare(
	catch2
	GIT_REPOSITORY https://github.com/catchorg/Catch2.git
	GIT_TAG        origin/v2.x
)
FetchContent_MakeAvailable(catch2)

add_executable(
	${PROJECT_NAME}
	"main.cpp"
)

target_link_libraries(
	${PROJECT_NAME}
	PRIVATE
	CppSteg
	Catch2::Catch2
)

add_test(CppStegLogSuit ${PROJECT_NAME})