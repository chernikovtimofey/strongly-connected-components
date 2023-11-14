cmake_minimum_required(VERSION 3.0.0)
project(StronglyConnectedComponents VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(MakeAdjacencyListTest tests/make-adjacency-list-test.cpp)
add_executable(FinishTimeTest tests/finish-time-test.cpp)
add_executable(GraphTranspositionTest tests/graph-transposition-test.cpp)
add_executable(FindSCCTest tests/find-SCC-test.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
