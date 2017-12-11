#include <iostream>
#include <string>

using namespace std;

struct wordNode
{
    string data; //value

    wordNode *left; //left pointer 
    wordNode *right; //right pointer 
};

class wordTree
{
    private:
        wordNode *root;

        void addPrivate( string v , wordNode *ptr ) ;

    public:
        wordTree() : root( nullptr ) {} ;  //default constructor

        //wordTree( const wordTree &rhs );  //copy constructor 

        //const wordTree &operator=( const wordTree &rhs );   //assignmnet operator



        wordNode* createLeaf( string v ); //creates leaf

        void add( string v ) ;   //adds a given word to the tree if it does not already exist & increments appropriate counter

        //int distinctWords() const;  //returns # of distinct words

        //int totalWords() const;   //returns # of total words including duplicate values 




        //friend ostream &operator<<( ostream &out , const wordTree &rhs ); //prints words of tree in alphabetical order and their occurance next to it

        ~wordTree(); //destructor
};