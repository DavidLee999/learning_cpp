#include <iostream>
#include <string>
//#include <vector>
using namespace std;

struct Work{
	string author;
	string name;
	int year;
};

int main()
{
	Work s9 { "Mike", "None", 1999 };
	
	Work s8 = s9;
	
	Work s7 {};
	
	cout << s9.author << " " << s9.name << " " << s9.year << endl;
	cout << s8.author << " " << s8.name << " " << s8.year << endl;
	cout << s7.author << " " << s7.name << " " << s7.year << endl;
	
	return 0;
}