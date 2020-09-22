cmake_minimum_required(VERSION 3.17)
project(cpp_playground)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_playground main.cpp OldResource.cpp ResourceWrapper.cpp OldResourceException.cpp OldResourceException.h)