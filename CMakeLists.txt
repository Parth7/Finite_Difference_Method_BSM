cmake_minimum_required(VERSION 3.17)
project(Euler_Finite_Difference_Method_BSM)

set(CMAKE_CXX_STANDARD 14)

add_executable(Euler_Finite_Difference_Method_BSM main.cpp payoff.h payoff.cpp option.h option.cpp pde.h pde.cpp fdm.h fdm.cpp)