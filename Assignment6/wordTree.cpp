#include<iostream>
#include<string>

#include "wordTree.h"

using namespace std;

//Private:
node* wordTree::createLeafPrivate(string v)
{
	node* n = new node;

	n->data = v;
	n->occurrence = 1;
	n->right = nullptr;
	n->left = nullptr;

	return n;
}

void wordTree::addLeafPrivate(string v, node* ptr)
{
	if (root == nullptr)
	{
		root = createLeaf(v);		//if root is empty, create leaf 
	}
	else if (v < ptr->data)			//if string less than node - go left
	{
		if (ptr->left != nullptr)
		{
			addLeafPrivate(v, ptr->left);		//if node exists, traverse down left
		}
		else
		{
			ptr->left = createLeaf(v);	//else create leaf
			dWords++;				//increment uniqueWords
		}
	}
	else if (v > ptr->data)				//if string greater than node - go right
	{
		if (ptr->right != nullptr)
		{
			addLeafPrivate(v, ptr->right);		//if node exists, traverse down right
		}
		else
		{
			ptr->right = createLeaf(v);	//else create leaf
			dWords++;				//increment uniqueWords
		}
	}
	else
	{
		ptr->occurrence += 1;
		tWords++ ;
	}
}

//IN-ORDER TRAVERSAL
void wordTree::printInOrderPrivate(node* ptr)
{
	if (root != nullptr)
	{
		if (ptr->left != nullptr)
		{
			printInOrderPrivate(ptr->left);			//go left until you reach the end
		}

		cout << ptr->data << " " << ptr->occurrence <<  endl;			//proccess current node

		if (ptr->right != nullptr)
		{
			printInOrderPrivate(ptr->right);		//go right until you reach the end
		}
	}
	else
	{
		cout << "The tree is empty..." << endl;
	}
}

//POST-ORDER TRAVERSAL
void wordTree::removeWordTree(node* ptr)
{
	if (ptr != nullptr)
	{
		if (ptr->left != nullptr)
		{
			removeWordTree(ptr->left);		//traverse all the way left
		}
		if (ptr->right != nullptr)
		{
			removeWordTree(ptr->right);		//traverse all the way right
		}

		delete ptr;							//deletes node
	}
}



//Public:
wordTree::wordTree()
{
	root = nullptr;
}

node* wordTree::createLeaf(string v)
{
	return createLeafPrivate(v);
}

void wordTree::addLeaf(string v)
{
	addLeafPrivate(v, root);
}

void wordTree::printInOrder()
{
	printInOrderPrivate(root);
}

int wordTree::distinctWords() const
{
	return dWords;
}

int wordTree::totalWords() const
{
	return tWords + distinctWords();
}

wordTree::~wordTree()
{
	removeWordTree(root);

	root = nullptr;
		
	cout << endl << "Tree has been deleted." << endl;
}