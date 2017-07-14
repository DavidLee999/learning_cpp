#include <iostream>
#include <typeinfo>
#include <unordered_map>
#include <map>

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
	map<int, char> s { {4,'a'}, {2,'k'}, {0,'2'}, {8,'o'} };
    s[5] = 'l';
    for( map<int, char>::const_iterator a = s.cbegin(); a != s.cend(); ++a )
        std::cout << (*a).first << " " << (*a).second << '\t';

    unordered_map<int, char> s2 { {4,'a'}, {2,'k'}, {0,'2'}, {8,'o'} };
    s2[0] = 't';
    std::cout << std::endl;
    for( unordered_map<int, char>::const_iterator a = s2.cbegin(); a != s2.cend(); ++a )
        std::cout << (*a).first << " " << (*a).second << '\t';
	return 0;
}
