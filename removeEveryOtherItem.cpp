#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <typename Container>
void removeEveryOtherItem( Container& lst )
{
    typename Container::iterator itr = lst.begin(); // Container::iterator itr + lst.begin();
    
    while( itr != lst.end() )
    {
        itr = lst.erase( itr );
        
        if( itr != lst.end() )
            ++itr;
    }
}

int main()
{
    vector<int> a {1,2,3,4,5,6,7,8};
    removeEveryOtherItem(a);
    
    for( int i = 0; i < a.size(); ++i )
        cout << a[i] << '\t';
    return 0;
}