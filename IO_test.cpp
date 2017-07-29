#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double a=123.456,b=3.14159,c=-3214.67;

    cout.precision( 2 );
    // cout.width( 10 );
    cout.setf( ios::right );
    cout.setf( ios::fixed );
    // cout << setiosflags( ios::fixed ) << setiosflags( ios::right ) << setprecision( 2 );
    cout << setw( 10 ) << a << '\n';
    cout << setw( 10 ) << b << '\n';
    cout << setw( 10 ) << c << endl;

    char ch[20];
    cin >> ch;
    cout << ch;
    cin.getline( ch, 20, '/' );
    cout << ch << endl;

    return 0;
}
