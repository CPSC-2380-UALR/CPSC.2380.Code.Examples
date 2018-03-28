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

	int NUM_NODES = 10;

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

	//display list in reverse order.:
	int listCount = 0;
	currNode = head;
	//count list;
	while (currNode!= nullptr)
	{
		currNode = currNode->next;
		listCount++;
	}
	//iterate over list the number of times it is in the list
	for (int i = listCount-1; i >= 0; i--)
	{
		currNode = head;
		//for each iteration stop one spot sooner
		for (int j = i; j > 0; j--)
		{
			currNode = currNode->next;
		}
		//print it to screen.
		cout << currNode->data << endl;
		
	}
	
	system("PAUSE");
	delete head;

	return 0;

}