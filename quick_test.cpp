#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;

int main()
{
	time_t timeBegin, timeEnd;  
    timeBegin = time(NULL);  
    Sleep(1000);  
    timeEnd = time(NULL);  
    printf("%d\n", timeEnd - timeBegin);  
      
      
    //用clock()来计时  毫秒  
    clock_t  clockBegin, clockEnd;  
    clockBegin = clock();  
    Sleep(800);  
    clockEnd = clock();  
    printf("%d\n", clockEnd - clockBegin);
	
	return 0;
}