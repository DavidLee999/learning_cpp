#include <iostream>
using namespace std;

#include "smartpointer.h"

class SomeClass {
    public:
        SomeClass()
        {
            std::cout << "SomeClass default constructor!" << '\n';
        }
};

void testcase1()
{
    SmartPointer<char> spunknown;

    SmartPointer<char> spnull = nullptr;

    SmartPointer<SomeClass> spclass = new SomeClass;

    SmartPointer<const char> spstr = "Hello world!";
}

int main()
{
    testcase1();

    return 0;
}
