#include <iostream>

using namespace std;


class Animal {
public:
    virtual void Bark() {
        cout << "叫" << endl;
    }
    int b = 2;
};


class CCat :public Animal {
public:
    void Bark() {
        cout << "喵喵" << endl;
    }
    int a = 1;
};



int main()
{
    Animal an1;
    CCat * cat1 = (CCat*) &an1;

    cat1->Bark();

    std::cout << "Hello World!\n";
}
