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
		node* root;

		node* createLeafPrivate(string v)
		{
			node* n = new node;

			n->data = v;
			n->right = nullptr;
			n->left = nullptr;

			return n;
		}

		void addLeafPrivate(string v, node* ptr)
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
				}
			}
			else
			{
				;
				//cout << "The word \"" << v << "\" has already been added" << endl;
			}
		}

		//IN-ORDER TRAVERSAL
		void printInOrderPrivate(node* ptr)
		{
			if (root != nullptr)
			{
				if (ptr->left != nullptr)
				{
					printInOrderPrivate(ptr->left);		//go left until you reach the end
				}

				cout << ptr->data << endl;			//proccess current node

				if (ptr->right != nullptr)
				{
					printInOrderPrivate(ptr->right);		//go right until you reach the end
				}
			}
			else
			{
				cout << "The tree is empty..." << endl ;
			}
		}

	public:
		wordTree()
		{
			root = nullptr;
		}

		node* createLeaf(string v)
		{
			return createLeafPrivate(v);
		}

		void addLeaf(string v)
		{
			addLeafPrivate(v, root);
		}

		void printInOrder()
		{
			printInOrderPrivate(root);
		}

		//POST-ORDER TRAVERSAL
		void removeWordTree(node* ptr)
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

		~wordTree()
		{
			removeWordTree(root);
			
			cout << endl << "Tree has been deleted." << endl;
		}
};