cmake_minimum_required(VERSION 3.3)

#c++ project
project(qsort CXX)
#include headers in the include folder
include_directories("${CMAKE_SOURCE_DIR}/include/")
#source files
set(LIB_SRCS "${CMAKE_SOURCE_DIR}/src/qsort.cc")
#build a shared library
add_library(qsort SHARED ${LIB_SRCS})

#test library with Coogle C++ Testing Framework
enable_testing()
include(ExternalProject)
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)

ExternalProject_Add(googletest
    GIT_REPOSITORY git@github.com:google/googletest.git
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)

include_directories(${EXTERNAL_INSTALL_LOCATION}/include)
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)

#testing source code
set(TEST_SRCS "${CMAKE_SOURCE_DIR}/test/qsort_test.cc")

#test executable
add_executable(qsort_test ${TEST_SRCS})
add_dependencies(qsort_test googletest)

#test executable is linked with the library produced above and the gtest lib
target_link_libraries(qsort_test qsort gtest pthread)

#do a test for ctest
add_test(qsort_test qsort_test)
