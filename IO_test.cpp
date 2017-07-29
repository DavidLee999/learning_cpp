#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

struct student{
    int num;
    char name[20];
    float score;
};

int main()
{
    student stud[5] {1001,"Li",85,1002,"Fun",97.5,1004,"Wang",54,1006,"Tan",76.5,1010,"ling",96};

    fstream iofile( "stud.dat", ios_base::out | ios_base::binary );
    if( !iofile )
    {
        cerr << "Open error!" << '\n';
        abort();
    }

    iofile.write( reinterpret_cast<char*>(&stud[0]), sizeof( stud ) );
    iofile.close();

    iofile.open("stud.dat", ios_base::out |ios_base::in | ios_base::binary );
    student stud1[5];
    for( int i = 0; i < 5; i += 2)
    {
        iofile.seekg( i*sizeof( stud[i] ), ios_base::beg );
        iofile.read( reinterpret_cast<char*>(&stud1[i/2]), sizeof( stud1[0] ) );

        cout << stud1[i/2].num << " " << stud1[i/2].name << " " << stud1[i/2].score << '\n';
    }
    cout << endl;

    stud[2].num = 1012;
    strcpy( stud[2].name, "Wu" );
    stud[2].score = 60;

    iofile.seekp( 2*sizeof( stud[0] ), ios_base::beg );
    iofile.write( reinterpret_cast<char*>( &stud[2] ), sizeof( stud[2] ) );
    iofile.seekp( 0, ios_base::beg );

    for( int i = 0; i < 5; ++i )
    {
        iofile.read( reinterpret_cast<char*>( &stud[i] ), sizeof( stud[i] ) );
        cout << stud[i].num << " " << stud[i].name << " " << stud[i].score << '\n';
    }

    iofile.close();

    return 0;
}
