cmake_minimum_required(VERSION 3.30)
project(prueba1_omp)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenMP REQUIRED)
set(CMAKE_CXX_FLAGS "${CXX_CMAKE_FLAGS} -fopenmp")

add_executable(prueba1_omp main.cpp)

if(OpenMP_CXX_FOUND)
    target_link_libraries(prueba1_omp PUBLIC OpenMP::OpenMP_CXX)
endif()
