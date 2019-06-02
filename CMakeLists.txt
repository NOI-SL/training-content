cmake_minimum_required(VERSION 3.13)
project(noi-training-content)

set(CMAKE_CXX_STANDARD 14)

# Time Complexity
add_executable(time-complexity-loop1 time-complexity/loop1.cpp)
add_executable(time-complexity-loop2 time-complexity/loop2.cpp)
add_executable(time-complexity-loop3 time-complexity/loop3.cpp)

# Sorting
add_executable(sorting-bubble-sort sorting/bubble-sort.cpp)
add_executable(sorting-merge-sort sorting/merge-sort.cpp)

# Recursion
add_executable(recursion-factorial recursion/factorial.cpp)
add_executable(recursion-fibonacii recursion/fibonacii.cpp)

# Graph Traversal
add_executable(graph-traversal-bfs graph-traversal/bfs.cpp)
add_executable(graph-traversal-dfs graph-traversal/dfs.cpp)

# DAG
add_executable(dag-max-sum dag/max-sum.cpp)