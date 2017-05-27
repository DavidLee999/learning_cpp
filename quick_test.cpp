#include <iostream>
using namespace std;

class num{
private:
	int n;
	int m;
public:
	num(int i = {}, int j = {}):n{i}, m{j} {}
	
	void print() { cout << n << endl << m << endl; }
};

int main()
{
	num a{};
	
	a.print();
	
	num b{1,2};
	
	b.print();
	
	num c{1};
	
	c.print();
	
	return 0;
}