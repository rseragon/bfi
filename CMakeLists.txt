cmake_minimum_required(VERSION 3.14)

set(CMAKE_CPP_COMPILER "g++")

project(bfi VERSION 0.1 LANGUAGES CXX)

if (ASCII_TERMINAL)
	add_definitions(-DASCII_TERMINAL)
endif()


add_executable(${PROJECT_NAME} src/main.cpp src/config.cpp src/interpreter.cpp)
