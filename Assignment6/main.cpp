#include <iostream>
#include <string>

#include "wordTree.cpp"

//prototypes
void convertToLower( string &x ) ;

using namespace std;

int main()
{
    string x = "BeckY" ;

    convertToLower( x ) ;

    cout << x << endl ;   

}


void convertToLower( string &x )            //converts string to lower case
{
    for ( int i = 0 ; i < x.length()  ; i++ )
    {
        x[i] = tolower( x[i] ) ;
    }
}