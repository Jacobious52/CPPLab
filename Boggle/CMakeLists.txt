cmake_minimum_required(VERSION 3.3)
project(Boggle)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Boggle.cpp Boggle.h)
add_executable(Boggle ${SOURCE_FILES})