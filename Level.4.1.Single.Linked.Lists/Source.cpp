#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

int main()
{
	node* head = new node;
	head->next = nullptr;
	head->data = 0;

	const int NUM_NODES = 10;

	node* currNode = head;
	for (int i = 1; i < NUM_NODES; i++)
	{

		while (currNode->next != nullptr)
		{
			currNode = currNode->next;
		}
		node* temp = new node;
		temp->next = nullptr;
		currNode->next = temp;
		currNode = currNode->next;
		currNode->data = i;
	}

	//display list:
	currNode = head;
	while (currNode != nullptr)
	{
		cout << currNode->data << endl;
		currNode = currNode->next;
	}
	system("PAUSE");
	delete head;

	return 0;

}