/*
    Manuel Lara
    November 12 , 2017
    Assignment 4
    Pseudocode 

    main()
        first, create file handler 

        pass file handler to function to check whether file will open or not

        if target returns false, exit
    
    fileInput()
        ask for file name

        attepmt to open file

        if it fails
            return false
        if it works
            analyze file
            close file
            return true

    fileAnalysis()
        while not eof()
            read file 
            print line
            pass line filter function
        
        call transfer funtion

        call matching function
    
    filter()
        create whitelist of all the characters you want

        take every line and iterate through each character 
            if character is not a white space and is in the whitelist
                add character to stack 
    
    transfer()
        while not empty 
            copy stack into vector 
    
    matching()
        count how many times whitelist character appears in the vector 

        call matchingComments

        call matchingSingleQuotes

        call matchingDoubleQuotes

        call matchingBrackets

    matchingComments() - matchingsingleQuotes() - matchingDoubleQuotes() - matchingBrackets()
        compares open and close commnets comment 
            if theyre equal
                all comments balanced
            
            if theyre not equal 
                note which one is not equal 
*/

#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <vector>
#include <cctype>

using namespace std;

////prototypes
bool fileInput( ifstream &fin );
void fileAnalysis( ifstream &fin );
void printStatement( string line );
void filter( string line , stack<char> &stack );
void transfer( stack<char> &stack , vector<char> &vector );
void matching( vector<char> &vector );
void matchingComments( int openComment , int closeComment );
void matchingSingleQuote( int singleQuote );
void matchingDoubleQuote( int doubleQuote );
void matchingBrackets( int openBracket , int closeBracket ) ;

int main()
{
    ifstream fin;                           //file input

    bool target = fileInput( fin );       //returns file if valid 

    if ( target == false )
    {
        exit(0);                         //exit program if file doesnt exist
    }
}

bool fileInput( ifstream &fin )
{
    //string target = "sample.txt";       //file name
    string target ; 

    cout << "Enter file name: " ;
    cin >> target;

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
    vector<char> vector;                            //vector declaration

    while( !fin.eof() )                             //while not end of file
    {
        getline( fin , line );                      //gets line from file

        printStatement( line );                     //prints line 
        
        filter( line , stack );                     //characters are pushed onto stack 
    }

    ////stack populated  end->beginning
    
    transfer( stack , vector );                     //puts stack into vector 

    /////vector populated   end->beginning 

    matching( vector );                             //matches symbols and prints out message accordingly 

    /////////end
}

void printStatement( string line )
{
    cout << line << endl ;
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

    /////comments
    matchingComments( openComment , closeComment ) ;

    /////single quotes
    matchingSingleQuote( singleQuote );

    /////double quotes
    matchingDoubleQuote( doubleQuote ) ;

    /////brackets
    matchingBrackets( openBracket , closeBracket ) ;
}

void matchingComments( int openComment , int closeComment )
{
    if( openComment == closeComment ) 
    {
        while( openComment >= 0 )
        {
            cout << " /*  balanced by  */  " << endl ;
            openComment-- ;
        }
    }
    else
    {
        if( openComment > closeComment )
        {
           while( closeComment > 0 )
            {
                cout << " /*  balanced by  */  " << endl ;
                closeComment-- ;
            } 
        }

        if( openComment < closeComment )
        {
           while( openComment >= 0 )
            {
                cout << "' /* ' balanced by ' */ ' " << endl ;
                openComment-- ;
            } 
        }
    }
}

void matchingSingleQuote( int singleQuote )
{
    if( singleQuote % 2 == 0 )
    {
        while( singleQuote > 0 )
        {
            cout << " \' balanced by \' " << endl ;
        }
    }
    else
    {
        int x = singleQuote - 1 ;

        while( x > 0 )
        {
            cout << " \' balanced by \' " << endl ;
            x-- ;
        }
        cout << " 1 unbalanced \' " << endl; 
    }
}

void matchingDoubleQuote( int doubleQuote )
{
    if( doubleQuote % 2 == 0 )
    {
        while( doubleQuote > 0 )
        {
            cout << " \" balanced by \" " << endl ;
        }
    }
    else
    {
        int x = doubleQuote - 1 ;

        while( x > 0 )
        {
            cout << " \" balanced by \" " << endl ;
            x-- ;
        }

        cout << " 1 unbalanced \" " << endl; 
    }
}

void matchingBrackets( int openBracket , int closeBracket )
{
    if( openBracket == closeBracket ) 
    {
        while( openBracket > 0 )
        {
            cout << " {  balanced by  }  " << endl ;
            openBracket-- ;
        }
    }
    else
    {
        if( openBracket > closeBracket )
        {
            int x = openBracket - 1 ;

            while( closeBracket > 0 )
            {
                cout << " {  balanced by  }  " << endl ;
                closeBracket-- ;
            } 
            cout << "1 unbalanced {" << endl ;
        }

        if( openBracket < closeBracket )
        {
            int x = closeBracket - 1 ;

            while( openBracket > 0 )
            {
                cout << "{ balanced by } " << endl ;
                openBracket-- ;
            } 
            cout << "1 unbalanced }" << endl ;
        }
    }
}