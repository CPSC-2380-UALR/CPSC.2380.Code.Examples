#include <iostream>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

void insert(node* & root, int data);
node* insertRecursive(node*, int);

void printTreeLNR(node* currNode);
void printTreeLRN(node * currNode);
void printTreeNLR(node * currNode);

int main()
{
	int arrayForTree[6] = { 10, 20, 6, 18, 7, 2 };
	node* root = nullptr;
	for (auto item : arrayForTree)
	{
		insert(root, item);
		//root = insertRecursive(root, item);
	}

/*						10 <-- root
					  /    \
					6		20
				   / \	   /
				  2   7  18

*/
	printTreeLNR(root);
	cout << endl;
	printTreeLRN(root); //can recreate tree
	cout << endl;
	printTreeNLR(root); //can recreate tree
	cout << endl;
	system("PAUSE");
	return 0;
}

void insert(node* & root,  int data)
{
	node* temp = new node;
	temp->data = data;
	temp->left = nullptr;
	temp->right = nullptr;
	if (root == nullptr)
	{
		root = temp;
	}
	else
	{
		node* currNode = root;
		while (currNode != nullptr)
		{
			if (temp->data < currNode->data)
			{
				if (currNode->left == nullptr)
				{
					currNode->left = temp;
					return;
				}
				else
				{
					currNode = currNode->left;
				}
			}
			else
			{
				if (currNode->right == nullptr)
				{
					currNode->right = temp;
					return;
				}
				else
				{
					currNode = currNode->right;
				}
			}
		}

	}
}
node* insertRecursive(node* currNode, int data)
{
	if (currNode== nullptr)
	{
		node* temp = new node;
		temp->data = data;
		temp->left = nullptr;
		temp->right = nullptr;
		return temp;
	}
	if (data < currNode->data)
	{
		currNode->left = insertRecursive(currNode->left, data);
	}
	else if (data > currNode->data)
	{
		currNode->right = insertRecursive(currNode->right, data);
	}
	return currNode;

}

void printTreeLNR(node * currNode)
{
	if (currNode == nullptr)
	{
		return;
	}
	printTreeLNR(currNode->left);
	cout << currNode->data << ", ";
	printTreeLNR(currNode->right);
}

void printTreeNLR(node * currNode)
{
	if (currNode == nullptr)
	{
		return;
	}
	cout << currNode->data << ", ";
	printTreeNLR(currNode->left);
	printTreeNLR(currNode->right);
}

void printTreeLRN(node * currNode)
{
	if (currNode == nullptr)
	{
		return;
	}
	printTreeLRN(currNode->left);
	printTreeLRN(currNode->right);
	cout << currNode->data << ", ";
}
