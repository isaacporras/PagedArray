cmake_minimum_required(VERSION 3.9)
project(TareaCorta1)

set(CMAKE_CXX_STANDARD 11)

add_executable(TareaCorta1 main.cpp Memory/Memory.h PagedArray/Reader.cpp PagedArray/Reader.h Memory/Memory.cpp PagedArray/PagedArray.cpp PagedArray/PagedArray.h Sorting/Sorting.cpp Sorting/Sorting.hpp)