#include <iostream>
#include <memory>

using namespace std;

#include "cat.h"
#include "dog.h"
#include "ball.h"

int main()
{
    cout << "Dog and cat looks at the ball!" << endl;

    auto ball = std::make_shared<Ball>();

    auto cat = std::make_shared<Cat>("cat");

    auto dog = std::make_shared<Dog>("dog");

    ball->registerObserver(cat);
    ball->registerObserver(dog);

    std::cout<< "Ball jump...\n";
    ball->notifyObservers();

    std::cout<< "Cat left...\n";
    ball->removeObserver(cat);

    std::cout<< "Ball jump again...\n";
    ball->notifyObservers();

    return 0;
}
