#include <iostream>
#include <typeinfo>
using namespace std;

template <typename T>
class Complex{
public:
	T re, im;
	
public:
        //Complex( const T& r = T{}, const T& i = T{} ) : re { r }, im { i } { }
		constexpr Complex( const T& r = T{}, const T& i= T {} ) : re { r }, im { i } {}
		Complex( const Complex & rhs ) = default;
		Complex( Complex && rhs ) = default;
		Complex & operator = ( const Complex & rhs ) = default;
		Complex & operator = ( Complex && rhs ) = default;
		
		
		
		Complex & operator += ( const Complex);
};

template <typename T>
inline Complex<T> & Complex<T>::operator += ( const Complex rhs )
{
	re += rhs.re;
	im += rhs.im;
	
	return *this;
}

template <typename T>
Complex<T> operator + ( const Complex<T> lhs, const Complex<T> rhs )
{
	Complex<T> res { lhs };
	
	res += rhs;
	
	return res;
}

template <typename T, typename U>
Complex<T> operator + ( const Complex<T> lhs, const U rhs )
{
	Complex<T> res { lhs };
	
	res.re += static_cast<T> ( rhs );
	
	return res;
}

template <typename T, typename U>
Complex<T> operator + ( const U lhs, const Complex<T> rhs )
{
	Complex<T> res { rhs };
	
	res.re += static_cast<T> ( lhs );
	
	return res;
} 

constexpr Complex<double> operator ""_i ( long double d ) // require a constexpr constructor
{
	return Complex<double>{ 0.0, static_cast<double>( d ) };
}


int main()
{
	
	Complex<double> z1 { 2.2, 3.1 };
	
	const Complex<double> z2 = z1 + 2.1_i;
	
	Complex<double> z3 { 2.2 };
	
	z1 = z1 + 2;
	
	//z2 = 3 + z2;
	
	cout << z1.re << " " << z1.im << endl;
	cout << z2.re << " " << z2.im << endl;
	
	return 0;
}