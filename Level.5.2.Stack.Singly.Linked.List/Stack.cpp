#include <iostream>
#include "Stack.h"
using namespace std;
Stack::Stack()
{
	head = nullptr;
}
Stack::~Stack()
{
	node* deleteMe;
	while (head != nullptr)
	{
		deleteMe = head;
		head = head->next;
		delete deleteMe;
	}
}

int Stack::pop()
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

void Stack::push(int data)
{
	node * tempNode = new node;
	tempNode->data = data;
	tempNode->next = nullptr;

		tempNode->next = head;
		head = tempNode;


}

int Stack::peek()
{
	if (this->head == nullptr)
	{
		cout << "ERROR: The Stack is empty" << endl;
	}
	else
	{
		return this->head->data;
	}
	return 0;
}

bool Stack::isEmpty()
{
	if (this->head == nullptr)	return true;
	else return false;
}

int Stack::getLength()
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
void Stack::printStack()
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