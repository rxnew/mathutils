cmake_minimum_required(VERSION 2.8)

project(mathutils CXX)

set(TARGET mathutils)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/mathutils)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)

include_directories(${SOURCE_DIR})

install(DIRECTORY ${SOURCE_DIR}/
        DESTINATION include/${TARGET}
        FILES_MATCHING PATTERN *.hpp)

option(MATHUTILS_BUILD_TESTS "Build unit tests" off)

if(MATHUTILS_BUILD_TESTS)
  enable_testing()
  add_subdirectory(${TEST_DIR})
endif()

set(CMAKE_CXX_FLAGS "")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O2")

add_definitions(${CMAKE_CXX_FLAGS} "-std=c++14 -Wall")
