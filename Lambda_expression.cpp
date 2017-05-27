#include <iostream>
using namespace std;



int main()
{
	int y {}, c {};
	
	cin >> y >> c;
	
	[&y](int a) mutable ->int { return y = ( y > 0 ) ? y + a : -y + a; } (c);
	
	cout << endl << y;
	return 0;
}