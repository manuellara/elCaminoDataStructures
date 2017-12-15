#include<iostream>
#include<string>
#include<cctype>
#include<fstream>
#include<vector>

#include "wordTree.h"

using namespace std;

//converts string to lowercase
void convertToLower(string &x)
{
	for (int i = 0; i != x.length(); i++)
	{
		x[i] = tolower(x[i]);
	}
}

//reads file
bool readFile(vector<string> &v)
{
	string word;

	string target = "doi.txt";		//sample file
	ifstream fin;					//file handler 

	fin.open(target);				//apttempt to open sample file

	if (fin.fail())			
	{
		return false;				//if fail - return false
	}
	else
	{
		while (!fin.eof())
		{
			fin >> word ;				//gets single word from sample file
			v.push_back(word);
		}
		return true;
	}
}

//cleans up text
void filter(vector<string> &v)
{
	string word;

	for (int i = 0 ; i != v.size() ; i++)				//for every word in vector
	{
		for (int j = 0 ; j != v[i].length() ; j++)		//for every char in word
		{
			if ( isalpha(v[i][j]) )
			{
				word += v[i][j];						//if alpha, consctuct word with char
			}
		}
		v[i] = word;									//replace old word with filtered entry 
		word = "";
	}
}

//clean up white spaces 

int main()
{
	vector<string> vector;

	bool read = readFile(vector);			//call readFile and pass in vector

	if (!read)
	{
		cout << "File was not read in properly..." << endl;

		exit(0);
	}
	else
	{
		filter(vector);			//filter

		for (int i = 0; i != vector.size(); i++)
		{
			convertToLower(vector[i]);
		}
	}

	for (int i = 0 ; i != vector.size()-1 ; i++)
	{
		cout << vector[i] << endl;
	}

	/*wordTree myTree;

	for (int i = 0 ; i != vector.size()-1 ; i++)
	{
		myTree.addLeaf(vector[i]);
	}

	myTree.printInOrder();

	myTree.~wordTree();*/



	getchar();									//pause before exiting
}