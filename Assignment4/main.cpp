#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <vector>
#include <cctype>

using namespace std;

////prototypes
bool fileInput( ifstream &fin );
void printStatement( string line );
void fileAnalysis( ifstream &fin );
void filter( string line , stack<char> &stack );
void transfer( stack<char> &stack , vector<char> &vector );
void matching( vector<char> &vector );

int main()
{
    ifstream fin;                           //file input
    ofstream fout;                          //file output

    bool target = fileInput( fin );       //returns file if valid 

    if ( target == false )
    {
        exit(0);                         //exit program if file doesnt exist
    }
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
void printStatement( string line )
{
    cout << line << endl ;
}

void fileAnalysis( ifstream &fin )
{
    string line;
    stack<char> stack;                              //stack of char
    vector<char> vector;                            //vector declaration

    while( !fin.eof() )                             //while not end of file
    {
        getline( fin , line );                      //gets line from file

        //printStatement( line );                     //prints line 
        
        filter( line , stack );                     //characters are pushed onto stack 
    }

    ////stack populated  end->beginning
    
    transfer( stack , vector );                     //puts stack into vector 

    /////vector populated   end->beginning 

    matching( vector );
}

void filter( string line , stack<char> &stack )
{    
    char whiteList[] = { '\'' , '\"' , '{' , '}' , '*' , '/' };

    for ( int i = 0 ; i < line.length() ; i++ )
    {
        for( int x = 0 ; x < 6 ; x++ )
        {
            if( !isspace( line[i] ) && line[i] == whiteList[x] )      //if character is not white space AND is in the whitelist
            {
                stack.push( line[i] );                                //adds to stack
            }
        }
    }
}

void transfer( stack<char> &stack , vector<char> &vector )
{
    while( !stack.empty() )
    {
        vector.push_back( stack.top() );            //transfers stack to vector 
        stack.pop();
    }
}

void matching( vector<char> &vector )
{
    char whiteList[] = { '\'' , '\"' , '{' , '}' , '*' , '/' };

    int openComment = 0 , closeComment = 0 , singleQuote = 0 , doubleQuote = 0 , openBracket = 0 , closeBracket = 0;

    for( int i = vector.size() ; i >= 0 ; i-- )
    {
        if( vector[i] == whiteList[5] && vector[i+1] == whiteList[4] ) //open comment block
        {
            openComment += 1 ;
        }

        if( vector[i] == whiteList[4] && vector[i+1] == whiteList[5] ) //close comment block
        {
            closeComment += 1 ;
        }

        if( vector[i] == whiteList[0] )  //single quote
        {
            singleQuote += 1 ;
        }

        if( vector[i] == whiteList[1] )  //double quote
        {
            doubleQuote += 1 ;
        }

        if( vector[i] == whiteList[2] )  //open bracket
        {
            openBracket += 1 ;
        }

        if( vector[i] == whiteList[3] )  //close bracket
        {
            closeBracket += 1 ;
        }
    }

    cout << openComment << endl ;
    cout << closeComment << endl ;

}

