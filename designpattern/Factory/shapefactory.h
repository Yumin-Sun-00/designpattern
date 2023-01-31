#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include "Shape.h"

enum class ShapeType
{
    Sqaure = 0, Triangle
};

class ShapeFactory
{
public:
    ShapeFactory();

    Shape* getShapeInstance(ShapeType type);
};

#endif // SHAPEFACTORY_H
