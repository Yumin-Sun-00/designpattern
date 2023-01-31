#pragma once

#include <iostream>
#include "shapedecorator.h"
class RedColorDecorator : public ShapeDecorator
{
public:

    RedColorDecorator(Shape* shapeDecorated) :
        ShapeDecorator(shapeDecorated)
    {
        std::cout<<"RedColorDecorator constrcuted\n";
    }

    void draw() override
    {
        std::cout<<"RedColorDecorator draw....\n";
        m_ShapeDecorated->draw();
        setRedBorder();
    }

private:
    void setRedBorder()
    {
        std::cout<<"add red border...\n";
    }

};
