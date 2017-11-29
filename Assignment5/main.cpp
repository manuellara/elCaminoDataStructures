#include <iostream>
#include <string>
#include <fstream>
#include <istream>

using namespace std;

////prototypes
void checkFile( istream &dictfile ) ;
string getAnagram() ;
int readDictionary( istream &dictfile , string dict[] ) ;
void permute( string word , string dict[] , int count ) ;
int recursivePermute( string word, const string dict[], int size, string results[] ) ;
int forLoop( int x ) ;

////const declarations 
const int MAXRESULTS = 20 ;
const int MAXDICTWORDS = 30000 ;

int main()
{
    ifstream dictfile;                                  //file input handler

    string dict[ MAXDICTWORDS ];                        //dictionary array declaration 

    int nwords ;                                        //variable for number of words in file

    dictfile.open("words.txt") ;                        //attempt to open "words.txt"

    checkFile( dictfile ) ;                             //prints error message if dictfile fails

    nwords = readDictionary( dictfile , dict ) ;        //returns number of words in "words.txt" - stores result in 'nwords'

    cout << "Number of words : " << nwords << endl ;
}

void checkFile( istream &dictfile )
{
    if ( !dictfile )
    {
        cout << "File not found" << endl ;
        exit( 0 ) ;
    }
}

string getAnagram()
{
    string anagram ;

    cout << "Enter an anagram: " ;
    getline( cin , anagram ) ;

    return anagram;
}

int readDictionary( istream &dictfile , string dict[] )
{
    int count = 0 ;                                     //initialize count

    while( !dictfile.eof() )                            //loop through dictfile
    {
        getline( dictfile , dict[count] ) ;             //add entry to dict[] array
        count++ ;                                       //increment count
    }

    //string word = getAnagram() ;                        //gets anagram
    string word = "phi" ;

    permute( word , dict , count ) ;                    //pass word ( dict , count ) into permute function

    return count ; 
}

void permute( string word , string dict[] , int count )
{
    string originalWord = word ;                        //saves copy of original word

    string results[ MAXRESULTS ] ;                      //initialize results array - all permutations of anagram are placed here

    int x = 0 ;                                         //counter variable

    do
    {
        results[ x ] = word ;                           //add word permutation to results array
        x++ ;                                           //iterates through result array

    } while( next_permutation( word.begin(), word.end() ) ) ;

    int matches = recursivePermute( originalWord , dict , count , results ) ;       //returns matches 

    cout << "Word : " << originalWord << endl ;
    cout << "Matches : " << matches << endl ;
}

int recursivePermute( string word, const string dict[], int size, string results[] )
{
    int match = 0 ;

    //for( int i = 0 ; i < size ; i++ )                     // working return //
    //{
        //for( int x = 0 ; x < MAXRESULTS ; x++ )
        //{
            //if( dict[ i ] == results[ x ] )
            //{
                //match++ ;
            //}
        //}
    //}

    forLoop( size ) ;                                       //call recursive for loop

    return match ;
}

int forLoop( int x )                                   //recursive outer loop
{
    if ( x == -1 )
    {
        return -1 ;
    }

    cout << x << endl ;

    return x + forLoop( x - 1 ) ;
}

