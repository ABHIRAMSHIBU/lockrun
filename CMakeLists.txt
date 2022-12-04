cmake_minimum_required(VERSION 3.1...3.25)

project(
  LockRun
  VERSION 1.0
  LANGUAGES CXX C)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -pedantic")

set(CMAKE_DEBUG_POSTFIX d)

file(GLOB SRCS *.cc)

if( UNIX )
    message(STATUS "Host OS is UNIX/LINUX, proceeding.")
    add_executable(lockrun ${SRCS})
    target_include_directories(lockrun PRIVATE ${CMAKE_SOURCE_DIR})
    set_target_properties(lockrun PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
else( UNIX )
    message(FATAL_ERROR "This project only works in UNIX/LINUX environment")
endif( UNIX)