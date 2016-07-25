cmake_minimum_required(VERSION 3.3)

#c++ project
project(sort CXX)
#include headers in the include folder
include_directories("${CMAKE_SOURCE_DIR}/include/")
#source files
set(SORT_LIB_SRCS "${CMAKE_SOURCE_DIR}/src/qsort.cc"
                  "${CMAKE_SOURCE_DIR}/src/merge_sort.cc")
#build a shared library for the sort algorithms
add_library(sort SHARED ${SORT_LIB_SRCS})

#build a shared library for the select algorithms
set(SELECT_LIB_SRCS "${CMAKE_SOURCE_DIR}/src/local_minimum.cc")
add_library(select SHARED ${SELECT_LIB_SRCS})

#test library with Coogle C++ Testing Framework
include(ExternalProject)
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)

ExternalProject_Add(googletest
    GIT_REPOSITORY git@github.com:google/googletest.git
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)

include_directories(${EXTERNAL_INSTALL_LOCATION}/include)
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)

#testing source code for the sort algorithms
set(SORT_TEST_SRCS "${CMAKE_SOURCE_DIR}/test/sort_test.cc")

#sort test executable
add_executable(sort_test ${SORT_TEST_SRCS})
add_dependencies(sort_test googletest)

#sort test executable is linked with the library produced above and the gtest lib
target_link_libraries(sort_test sort gtest pthread)

#testing source code for the select algorithms
set(SELECT_TEST_SRCS "${CMAKE_SOURCE_DIR}/test/local_minimum_test.cc")

#select test executable
add_executable(select_test ${SELECT_TEST_SRCS})
add_dependencies(select_test googletest)

#select test executable is linked with the library produced above and the gtest lib
target_link_libraries(select_test select gtest pthread)
