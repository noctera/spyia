cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

project(CppSteg_Test)

include(FetchContent)

CPMAddPackage("gh:catchorg/Catch2@2.5.0")
add_executable(
	${PROJECT_NAME}
	"main.cpp"
	"BinToText.cpp"
	"TextToBin.cpp"
	"BinToDec.cpp"
	"DecToBin.cpp"
	
)

target_link_libraries(
	${PROJECT_NAME}
	PRIVATE
	CppSteg
	Catch2::Catch2
)

add_test(CppStegTestSuite ${PROJECT_NAME})