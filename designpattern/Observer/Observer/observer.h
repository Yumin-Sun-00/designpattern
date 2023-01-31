#pragma once
#include <string>
class Observer
{
public:
    Observer() = delete;
    explicit Observer(const std::string& id) :
        m_Id(id)
    {
    }
    virtual void update() = 0;

    bool operator==(const Observer& rhs)
    {
        return this->m_Id == rhs.m_Id;
    }

    bool operator!=(const Observer& rhs)
    {
        return !(*this== rhs);
    }

protected:
    std::string m_Id;
};
