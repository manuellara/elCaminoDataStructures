#include<iostream>
#include<string>

using namespace std;

struct node
{
	string data;
	node* left;
	node* right;
};

class wordTree
{
	private:
		node * root;

		node* createLeafPrivate(string v);

		void addLeafPrivate(string v, node* ptr);

		void printInOrderPrivate(node* ptr);

		void removeWordTree(node* ptr);

	public:
		int dWords = 0;

		int tWords = 0;

		wordTree();

		node* createLeaf(string v);

		void addLeaf(string v);

		void printInOrder();

		int distinctWords() const;

		int totalWords() const;

		~wordTree();
};