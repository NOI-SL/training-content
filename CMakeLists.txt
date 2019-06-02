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
add_executable(recursion-fibonacci recursion/fibonacci.cpp)

# Graph Traversal
add_executable(graph-traversal-bfs graph-traversal/bfs.cpp)
add_executable(graph-traversal-dfs graph-traversal/dfs.cpp)

# DAG
add_executable(dag-max-sum dag/max-sum.cpp)

# Contests
## 2019
### Screening Test
add_executable(nirmanis-star-patterns-solution1 contests/2019/screening-test/1-nirmanis-star-patterns/nirmanis-star-patterns-solution1.cpp)
add_executable(nirmanis-star-patterns-solution2 contests/2019/screening-test/1-nirmanis-star-patterns/nirmanis-star-patterns-solution2.cpp)

add_executable(king-rawanas-palace-solution1 contests/2019/screening-test/2-king-rawanas-palace/king-rawanas-palace-solution1.cpp)
add_executable(king-rawanas-palace-solution2 contests/2019/screening-test/2-king-rawanas-palace/king-rawanas-palace-solution2.cpp)

add_executable(candy-combinations-solution1 contests/2019/screening-test/3-candy-combinations/candy-combinations-solution1.cpp)
add_executable(candy-combinations-solution2 contests/2019/screening-test/3-candy-combinations/candy-combinations-solution2.cpp)

add_executable(game-of-life-simulation-solution1 contests/2019/screening-test/4-game-of-life-simulation/game-of-life-simulation-solution1.cpp)
add_executable(game-of-life-simulation-solution2 contests/2019/screening-test/4-game-of-life-simulation/game-of-life-simulation-solution2.cpp)

add_executable(numbers-numbers-everywhere-solution1 contests/2019/screening-test/5-numbers-numbers-everywhere/numbers-numbers-everywhere-solution1.cpp)
add_executable(numbers-numbers-everywhere-solution2 contests/2019/screening-test/5-numbers-numbers-everywhere/numbers-numbers-everywhere-solution2.cpp)

add_executable(a-mouse-in-a-maze-solution1 contests/2019/screening-test/6-a-mouse-in-a-maze/a-mouse-in-a-maze-solution1.cpp)
add_executable(a-mouse-in-a-maze-solution2 contests/2019/screening-test/6-a-mouse-in-a-maze/a-mouse-in-a-maze-solution2.cpp)