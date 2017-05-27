#include <iostream>
using namespace std;



int main()
{
	int y {}, c {};
	
	cin >> y >> c;
	
	cout << endl << [&y](int a) mutable ->int { return ( y > 0 ) ? y + a : -y + a; } (c) <<endl;
	
	return 0;
}