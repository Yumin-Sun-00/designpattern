cmake_minimum_required(VERSION 3.5)

project(Observer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Observer
    observer.h
    cat.h cat.cpp
    dog.h dog.cpp
    subject.h
    ball.h ball.cpp
    main.cpp)

install(TARGETS Observer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
