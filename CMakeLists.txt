cmake_minimum_required(VERSION 2.8.4)
project(Register)

# set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

include_directories(
  ${PROJECT_SOURCE_DIR}/inc
  )

set(SOURCE_FILES
  demo/main.cpp
  demo/Animal.cc
  demo/Cat.cc
  src/ClassRegister.cc
  )

add_executable(Register ${SOURCE_FILES})
