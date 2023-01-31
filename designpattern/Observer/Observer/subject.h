#pragma once
#include "observer.h"
#include <memory>
class Subject
{
public:
    virtual void registerObserver(std::shared_ptr<Observer> o) = 0;
    virtual void removeObserver(std::shared_ptr<Observer> o) = 0;
    virtual void notifyObservers() = 0;
};
