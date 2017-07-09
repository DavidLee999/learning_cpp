#include <iostream>
#include <typeinfo>
#include <vector>

using namespace std;

template <typename T>
class Complex{
public:
	T re, im;
	
public:
    Complex( T& r = T(), T& i = T() ) : re { r }, im { i } {}
    constexpr Complex( const T& r = T(), const T& i = T() ) : re { r }, im { i } {}

    T& real() { return re; }
};

constexpr Complex<double> operator ""i ( long double d )
{
	return Complex<double>{ 0.0, static_cast<double>( d ) };
}


int main()
{
	vector<Complex<double>> z1{ {1, 2}, {3, 0}, {0, 2}, {2.3i} };

    vector<Complex<double>> z2 = z1;

    z2[2].real() = 3;

     for( int i = 0; i < z1.size(); ++i )
        cout << z1[i].re << " + " << z1[i].im << "i" << endl;

    for( int i = 0; i < z1.size(); ++i )
        cout << z2[i].re << " + " << z2[i].im << "i" << endl;

    vector<Complex<double>> z3;
    z3 = move(z1);

    z3[2].real() = 1;

    for( int i = 0; i < z1.size(); ++i )
        cout << z1[i].re << " + " << z1[i].im << "i" << endl;

    for( int i = 0; i < z3.size(); ++i )
        cout << z3[i].re << " + " << z3[i].im << "i" << endl;
	return 0;
}
