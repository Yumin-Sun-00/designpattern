#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

class Singelton
{
public:
    static Singelton& createInstance()
    {
        static Singelton s_instance; // static variable with block scope
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

class SingletonCallOnce{

  private:
    static std::once_flag initInstanceFlag;
    static std::once_flag destroyInstanceFlag;
    static SingletonCallOnce* instance;
    SingletonCallOnce()= default;
    ~SingletonCallOnce()=default;

  public:
    SingletonCallOnce(const SingletonCallOnce&)= delete;
    SingletonCallOnce& operator=(const SingletonCallOnce&)= delete;

    static SingletonCallOnce* getInstance(){
      std::call_once(initInstanceFlag,SingletonCallOnce::initSingleton);
      return instance;
    }

    static void destoryInstance(){
        std::call_once(destroyInstanceFlag,SingletonCallOnce::destroySingleton);
    }


    static void initSingleton(){

        std::cout<<"this thread id: "<< std::this_thread::get_id() << "constructed, ";
        instance= new SingletonCallOnce();
    }

    static void destroySingleton(){
        std::cout<<"this thread id: "<< std::this_thread::get_id() << "try to delete\n";
        // instance only exist if we call getInstance()
        if(instance)
        {
            std::cout<<"this thread id: "<< std::this_thread::get_id() << "destroyed\n";
            delete instance;
            instance =  nullptr;
        }
    }
};

SingletonCallOnce* SingletonCallOnce::instance= nullptr;
std::once_flag SingletonCallOnce::initInstanceFlag;
std::once_flag SingletonCallOnce::destroyInstanceFlag;


#define CALLONCE

#ifdef CALLONCE



int main(){

    std::cout<<"master thread id: "<< std::this_thread::get_id() <<std::endl;

    std::vector<std::thread> ts;
    ts.reserve(10);

    for(int i = 0; i < 10; i++)
    {
        ts.emplace_back(std::thread([](){
            SingletonCallOnce::getInstance();
            SingletonCallOnce::destoryInstance();}));
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

#else
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

#endif
