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

char* expand( const char* ptr, int n )
{
	char* p = new char[n];
	strcpy( p, ptr );
	return p;
}

void String::copy_from( const String& x )
{
	if ( x.sz <= short_max )
	{
		memcpy( this, &x, sizeof(x) );
		ptr = ch;
	}
	else
	{
		ptr = expand( x.ptr, x.sz + 1 );
		sz = s.sz;
		space = 0;
	}
}

void String::move_from( String& x )
{
	if ( x.sz <= short_max )
	{
		memcpy(this, &x, sizeof(x) );
		ptr = ch;
	}
	else
	{
		ptr = x.ptr;
		sz = x.sz;
		space = x.space;
		
		x.ptr = x.ch;
		s.sz = 0;
		s.ch[0] = 0;
	}
}

String::String() : sz { 0 }, ptr { ch } { ch[0] = 0; }

String::String( const char* p ) : sz { strlen(p) }, ptr { (sz <= short_max) ? ch : new char[sz + 1] }, space { 0 }
{
	strcpy(ptr, p);
}

String::String( const String& x )
{ copy_from( x ); }

String::String( String&& x )
{ move_from( x ); }

String& String::operator = ( cosnt Strng& x )
{
	if ( this == &x )
		return *this;
	char* p = ( short_max < sz ) ? ptr : 0;
	copy_from( x );
	delete[] p;
	
	return *this;
}

String& String::operator = ( String&& x )
{
	if ( this == &x )
		return *this;
	if ( short_max < sz ) 
		delete[] ptr;
	
	move_from( x );
	return *this;
}

String& String::operator += ( char c )
{
	if ( sz == short_max )
	{
		int n = sz + sz + 2;
		ptr = expand( ptr, n );
		space = n - sz - 2;
	}
	else if ( short_max < sz )
	{
		if ( space == 0 )
		{
			int n = sz + sz + 2;
			char* p = expand( ptr, n );
			delete[] ptr;
			ptr = p;
			space = n - sz - 2;
		}
		else
			--space;
	}
	
	ptr[sz] = c;
	ptr[++sz] = 0;
	
	return* this;
}
int hash( const String& s )
{
	int h { s[0] };
	
	for ( int i { 1 }; i != s.size(); i++ )
		h ^= s[i] >> 1;
	
	return h;
}
