#include <iostream>
#include <queue>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

void insert(node* & root, int data);
node* insertRecursive(node*, int);
node* search(node*, int);
node* breadthFirstSearch(node*);
node* remove(node*, int);

/*****Balancing a Tree*****/
void storeBSTNodes(node* root, vector<node*> & nodes);
node* buildTreeUtility(vector<node*> & nodes, int start, int end);
node* balanceTree(node* root);

void printTree(node*);

int main()
{
	int arrayForTree[5] = { 20, 6, 18, 7, 2 };
	node* root = nullptr;
	for (auto item : arrayForTree)
	{
		//insert(root, item);
		root = insertRecursive(root, item);
	}
	
	root = balanceTree(root);
	
	printTree(root);

	system("PAUSE");
	return 0;
}

void insert(node* & root, int data)
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
	if (currNode == nullptr)
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

node * search(node * root, int key)
{
	node* currNode = root;
	while (currNode != nullptr)
	{
		if (key == currNode->data)
		{
			return currNode;
		}
		else if (key < currNode->data)
		{
			currNode = currNode->left;
		}
		else
		{
			currNode = currNode->right;
		}
	}
	return nullptr; //not found
}

node * breadthFirstSearch(node * root)
{
	queue<node*> toVisit;
	if (root != nullptr)	toVisit.push(root);
	node* currNode = nullptr;
	while (!toVisit.empty())
	{
		currNode = toVisit.front();
		cout << currNode->data << " ";
		if (currNode->left != nullptr)
		{
			toVisit.push(currNode->left);
		}
		if (currNode->right != nullptr)
		{
			toVisit.push(currNode->right);
		}
		toVisit.pop();
	}
	cout << endl;
	return nullptr;
}

node * remove(node * root, int key)
{
	node* parent = nullptr;
	node* toRemove = root;
	while (toRemove != nullptr)
	{
		if (toRemove->data == key)//if we found a match
		{
			if (toRemove->left == nullptr && toRemove->right == nullptr) //removing a leaf;
			{

				if (parent == nullptr)//if the root is to be romoved
				{
					root = nullptr;
				}
				else if (parent->left == toRemove)
				{
					parent->left == nullptr;
				}
				else
				{
					parent->right == nullptr;
				}
				delete toRemove;
				return root;
			}
			else if (toRemove->left != nullptr && toRemove->right == nullptr) //remove node with only left node
			{
				if (parent == nullptr)
				{
					root = toRemove->left;
				}
				else if (parent->left == toRemove)
				{
					parent->left = toRemove->left;
				}
				else
				{
					parent->right = toRemove->left;
				}
				delete toRemove;
				return root;
			}
			else if (toRemove->left != nullptr && toRemove->right == nullptr) //remove node with only right node
			{
				if (parent == nullptr)
				{
					root = toRemove->right;
				}
				else if (parent->left == toRemove)
				{
					parent->left = toRemove->right;
				}
				else
				{
					parent->right = toRemove->right;
				}
				delete toRemove;
				return root;
			}
			else //removes node with two children
				 //find successor (leftmost child of right subtree)
			{
				node* successor = toRemove->right;
				while (successor->left != nullptr)
				{
					successor = successor->left;
				}
				toRemove->data = successor->data;
				remove(toRemove->right, successor->data);
				return root;
			}
		}
		else if (toRemove->data < key)
		{
			parent = toRemove;
			toRemove = toRemove->right;
		}
		else
		{
			parent = toRemove;
			toRemove = toRemove->left;
		}
	}
	return root;
}

void storeBSTNodes(node * root, vector<node*>& nodes)
{
	if (root != nullptr)
	{
		storeBSTNodes(root->left, nodes);
		nodes.push_back(root);
		storeBSTNodes(root->right, nodes);
	}
}

node * buildTreeUtility(vector<node*>& nodes, int start, int end)
{
	if (start > end) return nullptr;

	//get middle element
	int mid = (start + end) / 2;
	node* root = nodes[mid];

	//recurse using inorder traversal
	root->left = buildTreeUtility(nodes, start, mid - 1);
	root->right = buildTreeUtility(nodes, mid + 1, end);
	return root;
}

node * balanceTree(node * root)
{
	vector<node*> nodes;
	storeBSTNodes(root, nodes);
	int n = nodes.size();
	return buildTreeUtility(nodes, 0, n - 1);
}

void printTree(node * currNode)
{
	if (currNode == nullptr)
	{
		return;
	}
	printTree(currNode->left);
	cout << currNode->data << ", ";
	printTree(currNode->right);
}
