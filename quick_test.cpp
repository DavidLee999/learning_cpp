#include <iostream>
using namespace std;

int main()
{
	int a = 2;
	
	char* p = reinterpret_cast<char*>(&a);
	
	cout<<*p;

	return 0;
}