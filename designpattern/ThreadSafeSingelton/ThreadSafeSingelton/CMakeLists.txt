cmake_minimum_required(VERSION 3.5)

project(ThreadSafeSingelton LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ThreadSafeSingelton main.cpp)

install(TARGETS ThreadSafeSingelton
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
