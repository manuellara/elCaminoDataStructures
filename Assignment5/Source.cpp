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
void permuteForLoop(string a, int i, int n, int j , string dict[] , int size , string results[] );
void checkFile(istream &dictfile);
string getAnagram();
int readDictionary(istream &dictfile, string dict[]);
int recursivePermute(string word, const string dict[], int size, string results[]);
void forLoop(string word, const string dict[], int size, string results[]);
void readFile(istream &dictfile, string dict[], int &count);
void recurPrint(const string results[], int size);

////const declarations 
const int MAXRESULTS = 20;
const int MAXDICTWORDS = 30000;

int main()
{
	int match = 0;

	ifstream dictfile;                                  //file input handler

	string results[MAXRESULTS];
	string dict[MAXDICTWORDS];                        //dictionary array declaration 

	dictfile.open("words.txt");                        //attempt to open "words.txt"

	checkFile(dictfile);                             //prints error message if dictfile fails

	int nwords = readDictionary(dictfile, dict);        //returns number of words in "words.txt" - stores result in 'nwords'

	string word = getAnagram();                        //gets anagram - hard coded word
	//string word = "phi";

	int wordLen = word.length(); 

	permuteForLoop(word , 0, wordLen-1 , 0 , dict , nwords , results);				//permutation of word

	recurPrint(results, 0);

	cout << endl << "done." << endl;
	getchar();										//pause before exiting
}

void permuteForLoop(string a , int i , int n , int j, string dict[], int nwords, string results[])
{
	if (i == n)
	{
		recursivePermute(a, dict, nwords, results);			//passes every permutation to recursivePermute()
		//cout << a << endl;

		return;
	}

	if ( j <= n)
	{
		swap(a[i], a[j]);						//swaps first and last chars
		permuteForLoop(a, i+1 , n , j, dict, nwords, results);  	 // Choose the remaining letters
		if (j % 2 == 0)
		{
			swap(a[i], a[j]);    // Undo the previous swap so we can choose the next possibility for a[j]
		}
		permuteForLoop(a, i, n, j+1, dict, nwords, results );
	}

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

	cout << endl;

	return anagram;
}

int readDictionary(istream &dictfile, string dict[])
{
	int count = 0;                                     //initialize count

	readFile(dictfile, dict, count);

	return count;
}

void readFile(istream &dictfile, string dict[], int &count)
{
	if (dictfile.eof() || count == MAXDICTWORDS - 1)
	{
		return;
	}

	getline(dictfile, dict[count]);
	count++;

	readFile(dictfile, dict, count);
}

int recursivePermute(string word, const string dict[], int size, string results[])
{
	forLoop(word, dict, size, results);                                       //call recursive for loop

	return 0;
}

void forLoop(string word, const string dict[], int size, string results[])            //recursive outer loop
{
	bool x = true;
	int y = 0 ;

	if (size == -1)
	{
		return;                                                      //exit condition
	}

	if (dict[size] == word  )
	{
		if (x)
		{
			if (results[y].length() > 0)
			{
				y++;

				if (y == MAXRESULTS)
				{
					cout << "MAX RESULTS exceeded....." << endl;
					getchar();
					exit(0);
				}
			}
			else
			{
				x = false;
			}
		}

		results[y] = word;
	}

	forLoop(word, dict, size - 1, results);				//iterator 
}

void recurPrint(const string results[], int size)
{
	if ( size == 20)
	{
		return;
	}

	if (results[size].length() > 0)
	{
		cout << "Matching result: " << results[size] << endl;
	}

	recurPrint(results, size + 1);
}
