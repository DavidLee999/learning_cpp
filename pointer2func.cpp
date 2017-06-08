#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;


struct User{
	const char* name;
	const char* id;
	int dept;
};

void print_id(vector<User>& v)
{
	for (auto& x : v)
	{
		cout << x.name << '\t' << x.id << '\t' << x.dept << '\n';
	}
}

int cmp1 ( const void* p, const void* q )
{
	return strcmp(static_cast<const User*>(p)->name, static_cast<const User*>(q)->name);
}

int cmp2 ( const void* p, const void* q )
{
	return static_cast<const User*>(p)->dept - static_cast<const User*>(q)->dept;
}

using CFT = int(const void*, const void*);

void ssort ( void* base, size_t n, size_t sz, CFT cmp)
{
	for ( int gap = n/2; 0 < gap; gap /= 2)
	{
		for ( int i = gap; i != n; i++)
		{
			for ( int j = i - gap; 0 <= j; j -= gap)
			{
				char* b = static_cast<char*>(base);
				char* pj = b + j*sz;
				char* pjg = b + ( j + gap )*sz;
				
				if ( cmp(pjg, pj) < 0 )
				{
					for ( int k = 0; k != sz; k++)
					{
						char temp = pj[k];
						pj[k] = pjg[k];
						pjg[k] = temp;
					}
				}
			}
		}
	}
}

int main()
{
	vector<User> heads;
	heads.push_back( User { "Schryer N.L.", "nls", 11274 } );
	heads.push_back( User { "Schryer N.L.", "nls", 11275 } );
	heads.push_back( User { "Kernighan B.W.", "bwk", 11276 } );
	heads.push_back( User { "Sethi R.", "ravi", 11272 } );
	heads.push_back( User { "Szymanski T.G.", "tgs", 11273 } );
	heads.push_back( User { "Ritchie D.M.", "dmr", 11271 } );
	
	
	cout << "Heads in alphabetical order:\n";
	//ssort(&heads, 6, sizeof(User), cmp1);
	sort(heads.begin(), heads.end(), [](const User& x, const User& y){ return x.name[0] < y.name[0]; } );
	print_id( heads );
	cout << endl ;
	
	cout << "Heads in department number:\n";
	//ssort(&heads, 6, sizeof(User), cmp2);
	sort(heads.begin(), heads.end(), [](const User& x, const User& y){ return x.dept < y.dept; } );
	print_id( heads );
	cout << endl ;
	
	return 0;
}