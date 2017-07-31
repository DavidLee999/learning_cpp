#include <iostream>
#include <cstdarg>
using namespace std;

void call(int severity ...)
{
    va_list ap;
    va_start(ap, severity);

    for(;;){
        //The macro va_arg() is used to pick the unnamed arguments in order.
        //In each call, the programmer must supply a type.
        //so no template, no type deduction
        const char* p = va_arg(ap, const char*);

        if ( p == nullptr ) break;

        cout << p << ' ';
    }

    va_end(ap);

    cout << endl;

    if(severity) exit(severity);
}

int main()
{
    const char *p { "variable arguments" };
    const char *q { "a test" };

    int a = 65;

    call(1, p, "it's", q, &a, nullptr);

    return 0;
}
