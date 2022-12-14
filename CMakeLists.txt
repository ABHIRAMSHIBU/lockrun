# Copyleft 🄯 Abhiram Shibu 2022

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
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -pedantic -DNDEBUG")

set(CMAKE_DEBUG_POSTFIX d)

add_subdirectory(src)

if( UNIX )
    message(STATUS "Host OS is UNIX/LINUX, proceeding.")
    add_executable(lockrun ${SRCS})
    target_include_directories(lockrun PRIVATE ${CMAKE_SOURCE_DIR}/include())
    set_target_properties(lockrun PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
else( UNIX )
    message(FATAL_ERROR "This project only works in UNIX/LINUX environment")
endif( UNIX)