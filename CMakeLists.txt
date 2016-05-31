cmake_minimum_required(VERSION 3.5)
project(IntersCpp)

include_directories(include)
file(GLOB SOURCE_FILES "src/*" "src/Utils/*")
file(GLOB SOURCE_TEST_FILES "test/src/*")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(IntersCpp ${SOURCE_FILES} main.cpp)
add_executable(IntersCppTest ${SOURCE_FILES} ${SOURCE_TEST_FILES})