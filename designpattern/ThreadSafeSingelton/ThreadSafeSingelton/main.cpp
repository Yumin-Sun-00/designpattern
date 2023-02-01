#include <iostream>
#include <vector>
#include <thread>

class Singelton
{
public:
    static Singelton& createInstance()
    {
        static Singelton s_instance;
        return s_instance;
    }
private:
    Singelton()
    {
        std::cout<<"this thread id: "<< std::this_thread::get_id() << "constructed, ";
    }

    ~Singelton()
    {
        std::cout<<"this thread id: "<< std::this_thread::get_id() <<" destoyed\n";
    }

    Singelton(const Singelton& other) = delete;
    Singelton(Singelton&& other) = delete;
    //toodo copy assigtnment

};


int main()
{
    std::cout<<"master thread id: "<< std::this_thread::get_id() <<std::endl;

    std::vector<std::thread> ts;
    ts.reserve(10);

    for(int i = 0; i < 10; i++)
    {
        ts.emplace_back(std::thread([](){Singelton::createInstance();}));
    }

    for(auto& t : ts)
    {
        if(t.joinable())
        {
            t.join();
        }
    }

    return 0;
}
