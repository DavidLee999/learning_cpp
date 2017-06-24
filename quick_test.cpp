#include <iostream>
#include <typeinfo>

using namespace std;

template <typename T>
class Complex{
public:
	T re, im;
	
public:
		Complex( T& r = T(), T& i = T() ) : re { r }, im { i } {}
		constexpr Complex( const T& r = T(), const T& i = T() ) : re { r }, im { i } {}
		
};

constexpr Complex<double> operator ""i ( long double d )
{
	return Complex<double>{ 0.0, static_cast<double>( d ) };
}


int main()
{
	
	Complex<double> z1 { 2.3i };
	
	cout << typeid(z1).name() << endl;
	
	cout << z1.re << " " << z1.im << endl;
	
	return 0;
}