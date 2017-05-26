#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int a[3] {1,2,3};
	
	int* p = a;
	
	cout<<sizeof(int*)<<endl<<sizeof(int)<<endl;
	cout<<sizeof(p)<<endl<<sizeof(*p)<<endl<<endl;
	
	int a2[2][2] {{1,2},{3,4}};
	
	int (*p2)[2] = a2;
	
	cout<<sizeof(int [2])<<endl;
	cout<<sizeof(*p2)<<endl<<sizeof(*(*p2))<<endl;
	cout<<p2[1][1]<<endl<<*(*(p2+1)+1)<<endl;
	
	int (&r)[3] = a;
	
	cout<<r[2]<<endl;
	
	int (&r2)[2][2] = a2;
	cout<<r2[0][1]<<endl<<*(*(a2+0)+1)<<endl;
	
	return 0;
}
