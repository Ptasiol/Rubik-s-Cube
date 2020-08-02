cmake_minimum_required (VERSION 2.6)
project (App)

set(CMAKE_CXX_FLAGS "-std=c++11")

set(LINK_FLAGS "-std=c++11")

file (GLOB_RECURSE SOURCES ./src/*.cpp)

add_executable (${PROJECT_NAME} ${SOURCES})

target_link_libraries (${PROJECT_NAME} "-lGL -lGLU -lGLEW -lglfw")
