#pragma once
struct node
{
	int data;
	node* next;
};
class Stack
{
public:
	node* head;
	Stack();
	~Stack();
	int pop();
	void push(int data);

	int peek();
	bool isEmpty();
	int getLength();
	void printStack();

};
