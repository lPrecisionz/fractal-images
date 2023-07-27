cmake_minimum_required(VERSION 3.0.0)
project(fractal-images VERSION 0.1.0 LANGUAGES C CXX)

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "src/*.h")

add_executable(fractal-images ${SOURCES} ${HEADERS})
