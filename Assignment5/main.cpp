#include <iostream>
#include <string>
#include <fstream>

using namespace std;

////prototype
string getAnagram();

int main()
{
    ifstream fin;                           //file input handler

    //string anagram = getAnagram() ;
    string anagram = "hello" ;              //test anagram

    

}

string getAnagram()
{
    string anagram ;

    cout << "Enter an anagram: " ;
    getline( cin , anagram ) ;

    return anagram;
}