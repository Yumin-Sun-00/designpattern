#include <iostream>
#include "shapefactory.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    ShapeFactory fact;
    auto instance = fact.getShapeInstance(ShapeType::Sqaure);
    delete instance;
    return 0;
}
