#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};
//add item at certain place in list, returns pointer head;
//head is place = 0;
node* addItem(node* head, int place, int data);

//searches list for data and removes it. returns head.
node* removeItem(node* head, int data);


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

	char command;
	do
	{
		//display list:
		currNode = head;
		while (currNode->next != nullptr)
		{
			cout << currNode->data << endl;
			currNode = currNode->next;
		}
		cout << currNode->data << endl;

		cout << "(a)dd item or (r)emove item or (q)uit: ";
		cin >> command;
		int data = 0;
		int place = 0;
		switch (command)
		{
		case 'a':
			cout << endl << "What number do you want to add and where? ";
			cin >> data >> place;
			head = addItem(head, place, data);
			break;
		
		case 'r':
			cout << endl << "What number do you want to remove? ";
			cin >> data;
			head = removeItem(head, data);
			break;		
		}
		system("CLS");
	} while (command != 'q');

	delete head;

	return 0;

}
node* addItem(node* head, int place, int data)
{
	if (head != nullptr)
	{
		node* currNode = head;

		node* temp = new node;
		temp->data = data;
		temp->next = nullptr;

		if (place == 0)
		{

			temp->next = head;
			head = temp;
		}
		else
		{
			int i = 0;
			while (currNode->next != nullptr && i != place)
			{
				currNode = currNode->next;
				i++;
			}
			if (i == place)
			{
				temp->next = currNode->next;
				currNode->next = temp;
			}
		}
	}
	return head;
}

node* removeItem(node* head, int data)
{	

	//head
	//middle
	//tail
	//doesn't exist
	if (head != nullptr)
	{
		node* currNode = nullptr;
		if (head->data == data)
		{
			currNode = head;
			head = currNode->next;
		}
		else
		{
			node* prevnode = head;
			currNode = head->next;
			while (currNode != nullptr && currNode->data != data)
			{
				prevnode = currNode;
				currNode = currNode->next;
			}

			if (currNode != nullptr && currNode->data == data)
			{
				prevnode->next = currNode->next;
			}
		}


		delete currNode;
	}
	return head;
}