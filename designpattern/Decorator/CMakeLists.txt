cmake_minimum_required(VERSION 3.5)

project(decorator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(decorator
    Shape.h
    Shape.cpp
    triangle.h
    triangle.cpp
    square.h
    square.cpp

    shapedecorator.h
    RedColorDecorator.h

    main.cpp)

install(TARGETS decorator
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
