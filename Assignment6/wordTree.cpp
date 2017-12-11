#include <iostream>
#include <string>

#include "wordTree.h"

using namespace std;

//wordTree() - default constructor - sets root to 'nullptr'


//creates leaf
wordNode* wordTree::createLeaf( string v )    //creates new leaf
{
    wordNode *n = new wordNode ;

    n->data = v ;           //assigns value
    n->left = nullptr ;     //sets left to null
    n->right = nullptr ;    //sets right to null

    return n ;
}

//adds leaf to tree
void wordTree::add( string v )
{
    addPrivate( v , root ) ;        //calls private add function
}

void wordTree::addPrivate( string v , wordNode *ptr) 
{
    if( root == nullptr )           //if root is empty
    {
        root = createLeaf( v ) ;    //add leaf with value 'v'
    }
    else if( v < ptr->data )       //if value is less than current root value
    {
        if( ptr->left != nullptr )  //if left pointer is not empty
        {
            addPrivate( v , ptr->left ) ;   //move down left side - recursivly call itself
        }
        else
        {
            ptr->left = createLeaf( v ) ;   //add new leaf
        }
    }
    else if( v > ptr->data )       //if value is greater than current root value
    {
        if( ptr->right != nullptr )  //if left pointer is not empty
        {
            addPrivate( v , ptr->right ) ;   //move down right side - recursivly call itself
        }
        else
        {
            ptr->right = createLeaf( v ) ;      //addd new leaf
        }
    }
    else
    {
        cout << "The value " << v << " has already been added to the tree" << endl;
    }


}

void wordTree::printInOrder()
{
    printInOrderPrivate( root ) ;
}

//uses IN-ORDER traversal 
void wordTree::printInOrderPrivate( wordNode *ptr )
{
    if( root != nullptr )                           //if root is not null
    {
        if( ptr->left != nullptr )
        {
            printInOrderPrivate( ptr->left );        //go left
        }

        cout << ptr->left << endl ;                 //process current

        if( ptr->right != nullptr )
        {
            printInOrderPrivate( ptr->right );       //go right
        }

    }
    else
    {
        cout << "The tree is empty..." << endl ;
    }
}