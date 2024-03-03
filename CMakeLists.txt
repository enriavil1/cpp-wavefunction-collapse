cmake_minimum_required(VERSION 3.9)
project(
  cpp-wfc
  VERSION 1.0.0
  LANGUAGES CXX)

# Set C++ standard and features
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(${PROJECT_NAME} main.cpp)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/include>)
