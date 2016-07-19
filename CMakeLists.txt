cmake_minimum_required(VERSION 3.3)
project(qsort C)

include_directories("${CMAKE_SOURCE_DIR}/include")
set(LIB_SRCS "${CMAKE_SOURCE_DIR}/src/qsort.c")
add_library(qsort SHARED ${LIB_SRCS})

enable_testing()
set(TEST_SRCS "${CMAKE_SOURCE_DIR}/test/qsort_test.c")
add_executable(qsort_test ${TEST_SRCS})
target_link_libraries(qsort_test qsort)
add_test(NAME qsort_test 
         COMMAND sh -c "cat ${CMAKE_SOURCE_DIR}/resources/test0.txt | ./qsort_test"
)
