#include <iostream>
#include <cstdarg>
using namespace std;

void call(int severity ...)
{
	va_list ap;
	va_start(ap, severity);
	
	for(;;){
		const char* p = va_arg(ap, const char*);
		
		if (p == nullptr ) break;
		
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
	call(1, p, "it's", q,  &a, nullptr);
	
	return 0;
}