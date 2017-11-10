#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <cctype>

using namespace std;

////prototype
bool fileInput( ifstream &fin );
void fileAnalysis( ifstream &fin );
void push( string line , stack<char> &stack );
void filter( stack<char> &stack );

int main()
{
    ifstream fin;                           //file input
    ofstream fout;                          //file output

    bool target = fileInput( fin );       //returns file if valid 

}

bool fileInput( ifstream &fin )
{
    string target = "sample.txt";

    fin.open( target.c_str() );         //attempt to open target file

    if ( fin.fail() )           //if fin fails, exit - else return file 
    {
        cout << "File failed to open..." << endl;
        return false;
    }
    else
    {
        cout << "File opened successfully!" << endl;

        fileAnalysis( fin );

        fin.close();            //attempt to close

        return true;
    }
}

void fileAnalysis( ifstream &fin )
{
    string line;
    stack<char> stack;                              //stack of char

    while( !fin.eof() )                             //while not end of file
    {
        getline( fin , line );                      //gets line from file
        
        push( line , stack );                       //characters are pushed onto stack 
    }

    //////stack is populated

    filter( stack );                                //stack is passed to filter function

}

void push( string line , stack<char> &stack )
{
    //string invalid = "'";
    //char singleQ = invalid[0];              //single quote

    for ( int i = 0 ; i < line.length() ; i++ )
    {
        if( !isspace( line[i] ) )
        {
            stack.push( line[i] );
        }
    }
}

void filter( stack<char> &stack )
{
    string invalid = "'";
    char singleQ = invalid[0];              //single quote

    char doubleQ = '\"' ;                   //double quote

    char openP = '{' ; 
    char closeP = '}';                      //parenthesis

    char star = '*' ; 
    char fSlash = '/' ; 
    char bSlash = '\\' ;                     //comments

    char whiteList[] = { singleQ , doubleQ , openP , closeP , star , fSlash , bSlash };


}