#include <iostream>
#include <ostream>

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

template <typename T>
std::ostream& operator << ( std::ostream& out, const Complex<T>& obj )
{
    out << obj.re << '+' << obj.im << 'i';
    
    return out;
}
int main()
{
	
	Complex<double> z1 { 2 };
	
	Complex<double> z2 = z1 + 2.1_i;
	std::cout << z1 << std::endl << z2 << std::endl;
	
	
	return 0;
}