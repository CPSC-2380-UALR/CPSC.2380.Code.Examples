#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
	node* prev;
};

int main()
{
	node* head = new node;
	head->next = nullptr;
	head->prev = nullptr;
	head->data = 0;

	node* tail = head;

	const int NUM_NODES = 10;

	for (int i = 1; i < NUM_NODES; i++)
	{

		node* temp = new node;
		temp->next = nullptr;
		temp->prev = nullptr;
		tail->next = temp;
		tail->next->prev = tail;;
		tail = tail->next;
		tail->data = i;
	}

	//display list:

	node* currNode = head;
	cout << "FORWARD: " << endl;
	while (currNode!= nullptr)
	{
		cout << currNode->data << endl;
		currNode = currNode->next;
	}
	cout << "Backward: " << endl;
	currNode = tail;
	while (currNode != nullptr)
	{
		cout << currNode->data << endl;
		currNode = currNode->prev;
	}
	system("PAUSE");
	delete head;

	return 0;

}