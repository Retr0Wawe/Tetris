cmake_minimum_required(VERSION 3.14)

project(Tetris LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE TETRIS_INCLUDE ${PROJECT_SOURCE_DIR}/include/*.hpp)
file(GLOB_RECURSE TETRIS_SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_NAME}
	${TETRIS_INCLUDE}
	${TETRIS_SOURCES}
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)