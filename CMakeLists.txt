cmake_minimum_required(VERSION 3.3)
project(sort CXX)
#include headers in the include folder
include_directories("${CMAKE_SOURCE_DIR}/include/")
#source files
set(SORT_LIB_SRCS         "${CMAKE_SOURCE_DIR}/src/qsort.cc"
                          "${CMAKE_SOURCE_DIR}/src/merge_sort.cc")
set(SELECT_LIB_SRCS       "${CMAKE_SOURCE_DIR}/src/local_minimum.cc")
set(DYNAMIC_LIST_LIB_SRCS "${CMAKE_SOURCE_DIR}/src/dynamic_list.cc")
set(GRAPH_LIB_SRCS        "${CMAKE_SOURCE_DIR}/src/graph.cc")
#library targets
add_library(sort          SHARED ${SORT_LIB_SRCS})
add_library(select        SHARED ${SELECT_LIB_SRCS})
add_library(dynamic_list  SHARED ${DYNAMIC_LIST_LIB_SRCS})
add_library(graph         SHARED ${GRAPH_LIB_SRCS})
#test libraries with Coogle C++ Testing Framework
include(ExternalProject)
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)
ExternalProject_Add(googletest
    GIT_REPOSITORY git@github.com:google/googletest.git
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)
include_directories(${EXTERNAL_INSTALL_LOCATION}/include)
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)

#TESTING
#testing sources
set(SORT_TEST_SRCS         "${CMAKE_SOURCE_DIR}/test/sort_test.cc")
set(SELECT_TEST_SRCS       "${CMAKE_SOURCE_DIR}/test/local_minimum_test.cc")
set(DYNAMIC_LIST_TEST_SRCS "${CMAKE_SOURCE_DIR}/test/dynamic_list_test.cc")
set(GRAPH_TEST_SRCS        "${CMAKE_SOURCE_DIR}/test/graph_test.cc")
#test executables
add_executable(sort_test         ${SORT_TEST_SRCS})
add_executable(select_test       ${SELECT_TEST_SRCS})
add_executable(dynamic_list_test ${DYNAMIC_LIST_TEST_SRCS})
add_executable(graph_test        ${GRAPH_TEST_SRCS})

add_dependencies(sort_test googletest)
add_dependencies(select_test googletest)
add_dependencies(dynamic_list_test googletest)
add_dependencies(graph_test googletest)
target_link_libraries(sort_test sort gtest pthread)
target_link_libraries(select_test select gtest pthread)
target_link_libraries(dynamic_list_test dynamic_list gtest pthread)
target_link_libraries(graph_test graph gtest pthread)

#SPECIFIC PROBLEM SOLVERS
set(MIN_CUT_FINDER_SRCS "${CMAKE_SOURCE_DIR}/src/min_cut_finder")
find_package(Boost REQUIRED) #for tokenizer
include_directories(${Boost_INCLUDE_DIR})
add_executable(min_cut_finder ${MIN_CUT_FINDER_SRCS})
target_link_libraries(min_cut_finder graph ${Boost_LIBRARIES})

set(SCC_FINDER_SRCS "${CMAKE_SOURCE_DIR}/src/SCC_finder.cc")
add_executable(SCC_finder ${SCC_FINDER_SRCS})
