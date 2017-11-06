#include <iostream>
#include <string>
#include <fstream>

using namespace std;

////prototype
bool fileInput( ifstream &fin );
void fileAnalysis( ifstream &fin );

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

    while( !fin.eof() )                     //while not end of file
    {
        getline( fin , line );
        
        cout << line << endl;
    }

}