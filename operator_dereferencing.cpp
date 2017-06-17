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
	
	Ptr1* operator -> () const // return a pointer 
	{
		return ptr;
	} 
	
	/* Ptr1& operator -> () const // return the dereferencing, the address which holds the pointer *orig
	{
		return *ptr;
	} */
};

int main()
{
	Origin o;
	o.value = 9;
	
	Ptr1 p1;
	p1.orig = &o;
	
	cout << "&p1->value = " << &(p1->value) << endl;
	cout << "Ptr1: p1->value = " << p1->value << endl; // object to be "pointed" should have the same name of its definition
	                                                    // and cannot be "asigned" to an arbitrary name or the name of the pointer.
														
	Ptr2 p2;
	p2.ptr = &p1;
	
	cout << "Ptr2: p2->orig = " << p2->orig << endl; // pointed to the "final" object
	
	cout << "p1.operator->() = " << p1.operator->() << endl; // return a pointer, same as above
	
	cout << "p1.operator->()->value = " << p1.operator->()->value << endl;
	
	cout << "Ptr2: p2->orig->value = " << p2->orig->value << endl; // return the final value
	
	cout << "p2.operator->() = " << p2.operator->() << endl;
	
	cout << "p2.operator->()->orig = " << p2.operator->()->orig << endl;
	
	cout << "p2.operator->()->orig->value = " << p2.operator->()->orig->value << endl;
	
	cout << "p2.operator->()->operator->() = " << p2.operator->()->operator->() << endl;
	
	cout << "p2.operator->()->operator->()_value = " << p2.operator->()->operator->()->value << endl;
	return 0;
}