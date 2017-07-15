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

class A
{
    public:
        A(const char *s)
        {
            cout<<s<<endl;// ~A() {}
        }
};
class B : virtual public A
{
    public:
        B(const char *s1, const char *s2):A(s1)  {  cout<<s2<<endl; }
};
class C : virtual public A
{
    public:
        C(const char *s1, const char *s2):A(s1)  {  cout<<s2<<endl; }
};
class D : public B, public C
{
    public:
        D(const char *s1, const char *s2, const char *s3, const char *s4) :B(s1, s2), C(s1, s3), A(s1)
        {
            cout<<s4<<endl;
        }
};
int main()
{
    D *ptr = new D("class A", "class B", "class C", "class D");
    delete ptr;

    return 0;
}
