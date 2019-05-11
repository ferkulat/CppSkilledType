cmake_minimum_required(VERSION 3.14)
project(CppSkilledType  LANGUAGES CXX)
set(EXTERN_DEPENDENCIES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/extern)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules ${CMAKE_MODULE_PATH})
include(msvc_cplusplus)
include(catch2)
include(CTestConfig)
include(CTest)
include(warnings)

enable_testing()
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
#set(CMAKE_VERBOSE_MAKEFILE ON)
add_subdirectory(Tests)
