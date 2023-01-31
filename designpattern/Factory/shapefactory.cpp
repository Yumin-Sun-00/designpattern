#include "shapefactory.h"
#include "triangle.h"
#include "square.h"

ShapeFactory::ShapeFactory()
{

}

Shape *ShapeFactory::getShapeInstance(ShapeType type)
{
    switch (type)
    {
    case ShapeType::Sqaure:
        return new Square();
        break;
    case ShapeType::Triangle:
        return new Triangle();
        break;
    default:
        return nullptr;
        break;
    }
}
