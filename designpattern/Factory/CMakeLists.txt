cmake_minimum_required(VERSION 3.5)

project(factory LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



add_executable(factory
    Shape.h
    Shape.cpp
    shapefactory.h
    shapefactory.cpp
    triangle.h
    triangle.cpp
    square.h
    square.cpp
    main.cpp)

install(TARGETS factory
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
