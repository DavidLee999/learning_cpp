#include <iostream>
using namespace std;

struct Origin {
	int value;
};

struct Ptr1 {
	Origin* orig;
	
	Origin* operator -> () const
	{
		return orig;
	}
};

struct Ptr2 {
	Ptr1* ptr;
	
	Ptr1& operator -> () const
	{
		return *ptr;
	}
};

int main()
{
	Origin o;
	o.value = 9;
	
	Ptr1 p1;
	p1.orig = &o;
	
	cout << "Ptr1: p1->value = " << p1->value << endl; // object to be "pointed" should have the same name of its definition
	                                                    // and cannot be "asigned" to an arbitrary name.
														
	Ptr2 p2;
	p2.ptr = &p1;
	
	cout << "Ptr2: p2->value = " << p2->value << endl; // pointed to the "final" object
	
	 
	return 0;
}