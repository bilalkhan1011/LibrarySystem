cmake_minimum_required(VERSION 2.8)

project(library)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS "-std=c99 -fdump-rtl-expand")

add_executable(library LibraryMain.c users.c bookManagement.c)
