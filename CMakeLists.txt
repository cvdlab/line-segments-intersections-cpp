cmake_minimum_required(VERSION 3.5)
project(IntersCpp)

#SET(CMAKE_CXX_FLAGS "-std=c++0x")

include_directories(include)
#file(GLOB SOURCE_FILES "src/*" "src/Utils/LineUtils.cpp")
file(GLOB SOURCE_FILES "src/*" "src/Utils/*")
file(GLOB SOURCE_TEST_FILES "test/src/*")

# All code is taken from http://geomalgorithms.com/a09-_intersect-3.html

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#set(SOURCE_FILES main.cpp EventQueue.cpp EventQueue.h src/Utils/Point.cpp headers/Utils/Point.h src/SweepLine.cpp headers/SweepLine.h headers/Utils/Event.h src/Utils/Line.cpp headers/Utils/Line.h src/Utils/LineUtils.cpp headers/Utils/LineUtils.h headers/Utils/AVLTree.h src/Utils/Event.cpp src/Utils/AVLNode.cpp headers/Utils/AVLNode.h headers/Utils/Comparable.h src/Utils/LineComparable.cpp)
add_executable(IntersCpp ${SOURCE_FILES} main.cpp)
add_executable(IntersCppTest ${SOURCE_FILES} ${SOURCE_TEST_FILES})