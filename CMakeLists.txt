cmake_minimum_required(VERSION 3.17)
project(C_C___Traninning)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS -pthread)

add_executable(C_C___Traninning  IOinC.c)
add_executable(C_C___Traninning_main main.c)
add_executable(C_C___Traninning_calc calc.c)
add_executable(C_C___Traninning_thread thread_mutex.c)
#add_library(test_library STATIC calc.c)
#
#find_library(TEST_LIBRARY test_library lib)
#target_link_libraries(cm)