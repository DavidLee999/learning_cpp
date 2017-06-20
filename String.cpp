#include <string.h>

class String{
public:
    String();
	
	explicit String( const char* p );
	
	String( const String& );
	String& operator = ( const String& );
	
	String( String&& x );
	String& operator = ( String&& x );
	
	~String() { if ( short_max < sz ) delete() ptr; }
	
	char& operator [] ( int n ) { return ptr[n]; }
	char operator [] ( int n ) const { return ptr[n]; }
	
	char& at( int n ) { check( n ); return ptr[n]; }
	char at( int n ) const { check( n ); return ptr[n]; }
	
	String& operator += ( char c );
	
	const char* c_str() { return ptr; }
	const char* c_str() const { return ptr; }
	
    int size() const { return sz; }
	int capacity() const
	{ return ( sz <= short_max ) ? short_max : sz + space; }
	
	
private:
	static const int short_max = 15;
	int sz;
	char* ptr;
	union{
		int space;
		char ch[short_max + 1];
	};
	
	void check( int n ) const
	{
		if ( n < 0 || sz <= n )
			throw std::out_of_range( "String::at" );
	}
	
	void copy_from( const String& x );
	void move_from( String& x );
};




int hash( const String& s )
{
	int h { s[0] };
	
	for ( int i { 1 }; i != s.size(); i++ )
		h ^= s[i] >> 1;
	
	return h;
}