#include <iostream>
using namespace std;

template <typename T>
class Complex{
public:
	T re, im;
	
public:
		Complex( T r, T i ) : re { r }, im { i } {};
};
int main()
{
	Complex<int> a { 2, 2 };
	
	cout << a.re << " " << a.im << endl;
	
	Complex<double> b { 2.7, 2 };
	
	cout << b.re << " " << b.im << endl;
	
	return 0;
}