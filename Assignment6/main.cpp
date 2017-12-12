#include <iostream>
#include <string>

#include "wordTree.cpp"

//prototypes
void convertToLower( string &x ) ;

using namespace std;

int main()
{
    string treeData[5] = { "ECHo" , "BRAVO" , "AlPha" , "Delta" , "cHArlie" } ;

    for( int i = 0 ; i < 5 ; i++ )
    {
        convertToLower( treeData[i] ) ;
    }

    wordTree myTree ;

    for( int i = 0 ; i < 5 ; i++ )
    {
        myTree.add( treeData[i] ) ;
    }

    myTree.printInOrder();

}


void convertToLower( string &x )            //converts string to lower case
{
    for ( int i = 0 ; i < x.length()  ; i++ )
    {
        x[i] = tolower( x[i] ) ;
    }
}