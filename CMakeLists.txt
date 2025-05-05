cmake_minimum_required(VERSION 3.29)
project(Task3)

set(CMAKE_CXX_STANDARD 20)

add_executable(Task3_Deque main.cpp Deque.cpp)
add_executable(DequeTests test.cpp Deque.cpp)
