#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape
{
public:
    Triangle();

    ~Triangle();

    void draw() override;
};

#endif // TRIANGLE_H
