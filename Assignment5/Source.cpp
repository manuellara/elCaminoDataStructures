/*
Manuel Lara
CS2 - Assignmet 5 

stack size: 50000000

///main///
	declare file handler and dictionary array
	opens words.txt - checks if words.txt will open
	calls readdictionary and passes file handler and array

	getchar only serves to pauses the program 

//checkfile//
	if dictfile fails, program exits

//getAnagram//
	prompts the user for an anagream
	returns anagram

//readDictionary//
	calls readfile - passes file handler, dictionary array, and count
	getAnagram is called and return value is saved in 'word'
	calls permute - passes word , dict array , and count
	returns count

//readFile//
	if dictFile is at the end of the file - return

	otherwise populate dict
	increment counter

	call self again

//permute//
	declare results array

	permute word and populate results array with permutations

	call recursivePermute - pass word, dict, count, results

//recursivePermute//
	calls forloop - passes word , dict, count , results

//forloop//
	iterates through dict
	if size == -1, return

	otherwise store word in temp variable
	call innerLoop - pass temp , results , match , count

	call self again

//innerLoop//
	iterate through results - compare all of results to temp 
	if count == -1 , return

	if temp == results
	call recurPrint - pass results , count

	call self again

//recurPrint//
	prints out matching word
*/

#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <algorithm>

using namespace std;

////prototypes
void checkFile(istream &dictfile);
string getAnagram();
int readDictionary(istream &dictfile, string dict[]);
void permute(string word, string dict[], int count);
int recursivePermute(string word, const string dict[], int size, string results[]);
void forLoop(string word, const string dict[], int size, string results[], int &match);
void innerLoop(string word, string results[], int &match, int count);
void readFile(istream &dictfile, string dict[], int &count);
void recurPrint(const string results[], int size);

////const declarations 
const int MAXRESULTS = 20;
const int MAXDICTWORDS = 30000;

int main()
{
	ifstream dictfile;                                  //file input handler

	string dict[MAXDICTWORDS];                        //dictionary array declaration 

	dictfile.open("words.txt");                        //attempt to open "words.txt"

	checkFile(dictfile);                             //prints error message if dictfile fails

	int nwords = readDictionary(dictfile, dict);        //returns number of words in "words.txt" - stores result in 'nwords'

	getchar();
}

void checkFile(istream &dictfile)
{
	if (!dictfile)
	{
		cout << "File not found" << endl;
		exit(0);
	}
}

string getAnagram()
{
	string anagram;

	cout << "Enter an anagram: ";
	cin >> anagram;

	cin.ignore(128, '\n');

	return anagram;
}

int readDictionary(istream &dictfile, string dict[])
{
	int count = 0;                                     //initialize count

	readFile(dictfile, dict, count);

	string word = getAnagram() ;                        //gets anagram - hard coded word

	permute(word, dict, count);                    //pass word ( dict , count ) into permute function

	return count;
}

void readFile(istream &dictfile , string dict[], int &count)
{
	if (dictfile.eof())
	{
		return;
	}

	getline(dictfile, dict[count]);
	count++;

	readFile(dictfile, dict, count);
}

void permute(string word, string dict[], int count)
{
	string originalWord = word;                        //saves copy of original word

	string results[MAXRESULTS];                      //initialize results array - all permutations of anagram are placed here

	int x = 0;                                         //counter variable

	do
	{
		results[x] = word;                           //add word permutation to results array
		x++;                                           //iterates through result array

	} while (next_permutation(word.begin(), word.end()));

	int matches = recursivePermute(originalWord, dict, count, results);       //returns matches 
}

int recursivePermute(string word, const string dict[], int size, string results[])
{
	int match = 0;

	forLoop(word, dict, size, results, match);                                       //call recursive for loop

	return match;
}

void forLoop(string word, const string dict[], int size, string results[], int &match)            //recursive outer loop
{
	int count = 20;

	if (size == -1)
	{
		return;                                                      //exit condition
	}

	string temp = dict[size];									//gets word
	
	innerLoop(temp, results, match, count);						//inner for loop

	forLoop(word, dict, size - 1 , results, match);				//iterator 
}

void innerLoop( string word , string results[] , int &match, int count)
{
	if (count == -1)
	{
		return;
	}

	if ( word != "" && results[count] != "" )
	{
		if (word == results[count])
		{
			recurPrint(results, count);
			match++;
		}
	}

	innerLoop(word, results, match, count - 1);
}

void recurPrint(const string results[], int size)
{
	cout << "Matching word " << results[size] << endl;
}