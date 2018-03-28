#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
	node* prev;
};
//add item at certain place in list, returns pointer head;
//head is place = 0;
node* addItem(node* head, node* & tail, int place, int data);

//searches list for data and removes it. returns head.
node* removeItem(node* head, node* & tail, int data);


int main()
{
	node* head = new node;
	head->next = nullptr;
	head->prev = nullptr;
	head->data = 0;

	node* tail = head;

	int NUM_NODES = 10;

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

	char command;
	do
	{
		//display list
		node* currNode = head;
		while (currNode != nullptr)
		{
			cout << currNode->data << endl;
			currNode = currNode->next;
		}

		cout << "(a)dd item or (r)emove item or (q)uit: ";
		cin >> command;
		int data = 0;
		int place = 0;
		switch (command)
		{
		case 'a':
			cout << endl << "What number do you want to add and where? ";
			cin >> data >> place;
			head = addItem(head,tail, place, data);
			break;
		
		case 'r':
			cout << endl << "What number do you want to remove? ";
			cin >> data;
			head = removeItem(head,tail, data);
			break;		
		}
		system("CLS");
	} while (command != 'q');

	delete head;

	return 0;

}
node* addItem(node* head, node* & tail, int place, int data)
{
	if (head != nullptr)
	{
		node* currNode = head;

		//create node to insert
		node* temp = new node;
		temp->data = data;
		temp->next = nullptr;
		temp->prev = nullptr;
		
		//head case
		if (place == 0)
		{

			temp->next = head;
			head->prev = temp;
			head = temp;
		}
		else
		{
			int i = 0;
			// navigate to insertion point.
			while (currNode != nullptr && i != place)
			{
				currNode = currNode->next;
				i++;
			}
			if (i == place)
			{
				//insert before currNode
				temp->next = currNode;
				////tail case
				if (currNode == nullptr)
				{
					temp->prev = tail;
					tail->next = temp;
					tail = temp;
				}
				else
				{
					temp->prev = currNode->prev;
					currNode->prev->next = temp;
					currNode->prev = temp;
				}
			}
		}
	}
	return head;
}

node* removeItem(node* head, node* & tail, int data)
{	

	//head
	//middle
	//tail
	//doesn't exist
	if (head != nullptr)
	{
		node* currNode = head;
		//head case
		if (head->data == data)
		{
			head = currNode->next;
			head->prev = nullptr;
		}
		else
		{
			//find the data
			while (currNode != nullptr && currNode->data != data)
			{
				currNode = currNode->next;
			}

			//if we found it
			if (currNode != nullptr && currNode->data == data)
			{
				//cut currNode out of the list
				currNode->prev->next = currNode->next;
				//tail case
				if (currNode->next != nullptr)
				{
					currNode->next->prev = currNode->prev;
				}
			}
		}
		delete currNode;
	}
	return head;
}