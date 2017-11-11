#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <vector>
#include <cctype>

using namespace std;

////prototype
bool fileInput( ifstream &fin );
void fileAnalysis( ifstream &fin );
void filter( string line , stack<char> &stack , vector<string> &vector );

int main()
{
    ifstream fin;                           //file input
    ofstream fout;                          //file output

    bool target = fileInput( fin );       //returns file if valid 

}

bool fileInput( ifstream &fin )
{
    string target = "sample.txt";       //file name

    fin.open( target.c_str() );         //attempt to open target file

    if ( fin.fail() )                   //if fin fails, exit - else return file 
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
    vector<string> vector;                            //vector declaration


    while( !fin.eof() )                             //while not end of file
    {
        getline( fin , line );                      //gets line from file
        
        filter( line , stack , vector );                       //characters are pushed onto stack 
    }

    ////stack populated  end->beginning
    ////vector populated ( index ) beginning->end

    cout << stack.size() << endl;

    while( !stack.empty() )
    {
        cout << stack.top();
        stack.pop();
    }

    cout << endl;
}

void filter( string line , stack<char> &stack , vector<string>& vector )
{    
    char whiteList[] = { '\'' , '\"' , '{' , '}' , '*' , '/' };

    for ( int i = 0 ; i < line.length() ; i++ )
    {
        for( int x = 0 ; x < 6 ; x++ )
        {
            if( !isspace( line[i] ) && line[i] == whiteList[x] )      //if character is not white space AND is in the whitelist
            {
                stack.push( line[i] );              //adds to stack
            }
        }
    }
}