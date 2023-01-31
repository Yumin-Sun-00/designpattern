#include "triangle.h"
#include <iostream>
Triangle::Triangle()
{
    std::cout<<"Triangle constructed\n";

}

Triangle::~Triangle()
{
    std::cout<<"Triangle deconstructed\n";
}

void Triangle::draw()
{
    std::cout<<"draw tri\n";
}
