cmake_minimum_required(VERSION 3.10)
project(Raytracer)

set(CMAKE_CXX_STANDARD 17)


add_executable(Raytracer src/main.cpp)
include_directories(Raytracer src/includes)

