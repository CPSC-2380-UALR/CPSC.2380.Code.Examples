#include <iostream>
#include "Queue.h"
using namespace std;
Queue::Queue()
{
	head = nullptr;
}
Queue::~Queue()
{
	node* deleteMe;
	while (head != nullptr)
	{
		deleteMe = head;
		head = head->next;
		delete deleteMe;
	}
}

int Queue::pop()
{
	int data = 0;
	if (this->head == nullptr)
	{
		cout << "ERROR: List is empty!" << endl;
		return data;
	}

	node* deleteMe = head;
	data = this->head->data;
	this->head = this->head->next;
	delete deleteMe;
	

	return data;
}

void Queue::push(int data)
{
	node * tempNode = new node;
	tempNode->data = data;
	tempNode->next = nullptr;

	node* currNode = this->head;

	if (this->head == nullptr)
	{
		this->head = tempNode;
	}
	else
	{
		while (currNode->next != nullptr)
		{
			currNode = currNode->next;
		}
		currNode->next = tempNode;
	}
	

}

 int Queue::peek()
{
	if (this->head == nullptr)
	{
		cout << "ERROR: The Queue is empty" << endl;
	}
	else
	{
		return this->head->data;
	}
	return 0;
}

 bool Queue::isEmpty()
{
	if (this->head == nullptr)	return true;
	else return false;
}

 int Queue::getLength()
{
	int length = 0;
	node* currNode = this->head;

	if (this->head == nullptr)
	{
		return length;
	}
	else
	{
		while (currNode != nullptr)
		{
			length++;
			currNode = currNode->next;
		}
		return length;
	}

}
 void Queue::printQueue()
{
	node* currNode = this->head;
	if (!isEmpty())
	{
		for (int i = 0; i < getLength(); i++)
		{
			cout << "Node " << i << ": " << currNode->data << endl;
			currNode = currNode->next;
		}
	}
}