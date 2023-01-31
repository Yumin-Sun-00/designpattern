#include "square.h"
#include <iostream>
Square::Square()
{
    std::cout<<"Square constructed\n";
}

Square::~Square()
{
    std::cout<<"Square deconstructed\n";
}


void Square::draw()
{

    std::cout<<"draw square\n";
}
