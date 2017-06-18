#include <iostream>
#include <typeinfo>
using namespace std;

template <typename T>
class Complex{
public:
	T re, im;
	
public:
		//Complex( T& r, T& i = T{} ) : re { r }, im { i } {}
		constexpr Complex( const T& r = T{}, const T& i= T {} ) : re { r }, im { i } {}
		
		
		Complex & operator += ( const Complex & );
};

template <typename T>
inline Complex<T> & Complex<T>::operator += ( const Complex & rhs )
{
	re += rhs.re;
	im += rhs.im;
	
	return *this;
}

template <typename T>
Complex<T> operator + ( Complex<T> lhs, Complex<T> rhs )
{
	return lhs += rhs;
}

constexpr Complex<double> operator ""_i ( long double d )
{
	return Complex<double>{ 0.0, static_cast<double>( d ) };
}

constexpr int ipow( int x, int n ) { return ( n > 0 ) ? x * ipow( x, n-1 ) : 1; }

template<char c>
constexpr int b3_helper()
{
	static_assert( c < '3', "not a ternary digit" );
	return c;
}

template<char c, char... tail>
constexpr int b3_helper()
{
	static_assert( c < '3', "not a ternary digit" );
	return ipow( 3, sizeof...(tail)) * (c - '0') + b3_helper(tail...);
}

template<char... chars>
constexpr int operator ""_b3() { return b3_helper(chars...); }

int main()
{
	
	Complex<double> z1 { 2 };
	
	Complex<double> z2 = z1 + 2.1_i;
	cout << z2.re << " " << z2.im << endl;
	
	auto x = 201_b3;
	
	cout << x << endl;
	return 0;
}