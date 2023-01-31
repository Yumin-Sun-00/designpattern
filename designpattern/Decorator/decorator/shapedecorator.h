#ifndef SHAPEDECORATOR_H
#define SHAPEDECORATOR_H

#include "Shape.h"

class ShapeDecorator : public Shape
{
public:
    ShapeDecorator(Shape* shapeDecorated) :
        m_ShapeDecorated(shapeDecorated)
    {
        std::cout<<"Shape decorator constrcuted\n";
    }

    ~ShapeDecorator()
    {
        delete m_ShapeDecorated;
        std::cout<<"Shape decorator deconstrcuted\n";
    }

    virtual void draw() = 0;

protected:
    Shape* m_ShapeDecorated;
};

#endif // SHAPEDECORATOR_H
