#include <iostream>

using namespace std;

class Singelton
{
public:
    Singelton(const Singelton& other) = delete;

    static Singelton& get()
    {
        static Singelton s_instance;
        return s_instance;
    }

    static float data()
    {
        return get().getData();
    }


private:
    Singelton(){}

    float getData() const { return m_data; }

    float m_data = 0.5f;
    static Singelton s_instance;

};


int main()
{
    float f = Singelton::data();

    std::cout<<f<<std::endl;
    return 0;
}
