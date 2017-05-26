#include <iostream>
#include <cstdarg>
using namespace std;

void call(int severity ...)
{
	va_list ap;
	va_start(ap, severity);
	
	for(;;){
		char* p = va_arg(ap, char*);
		
		if (p == "end") break;
		
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
	
	call(1, p, "it's", q, "end");
	
	return 0;
}