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

int main()
{
    int* i = new int{ 2 };
    {
        SmartPointer<int> ptr1 { i };
        {
            SmartPointer<int> ptr2 { ptr1 };
            {
                SmartPointer<int> ptr3 = nullptr;

                ptr3 = ptr2;

                cout << *ptr1 << endl;
                *ptr3 = 20;
                cout << *ptr2 << endl;
            }
        }
    }

    return 0;
}
