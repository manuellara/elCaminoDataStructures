#include <iostream>
#include <string>

using namespace std;

class wordTree
{
    private:
    struct wordNode
    {
        string data; //value

        wordNode *left; //left pointer 
        wordNode *right; //right pointer 
    };

        wordNode *root; //root pointer


        void addPrivate( string v , wordNode *ptr ) ;

        void printInOrderPrivate( wordNode *ptr );

    public:
        wordTree() ;  //default constructor



        wordNode* createLeaf( string v ); //creates leaf

        void add( string v ) ;   //adds a given word to the tree if it does not already exist & increments appropriate counter

        void printInOrder();


        //int distinctWords() const;  //returns # of distinct words

        //int totalWords() const;   //returns # of total words including duplicate values 




        //~wordTree(); //destructor
};