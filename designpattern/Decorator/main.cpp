#include <iostream>

using namespace std;

// allow user to add new features to an existing object without modifying the structure
// decorator class -> wrapper class, keeping the signatures of class method intact
// makes use of abstract classes and interfaces with compisitions

#include "triangle.h"
#include "square.h"
#include "RedColorDecorator.h"


int main()
{
    cout << "Hello World!" << endl;

    Shape* tri = new Triangle();
    tri->draw();
    delete tri;


    Shape* redTriangle = new RedColorDecorator(new Triangle());
    redTriangle->draw();
    delete redTriangle;

    Shape* redSquare = new RedColorDecorator(new Square());
    redSquare->draw();
    delete redSquare;

    return 0;
}
