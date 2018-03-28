#pragma once
struct node
{
	int data;
	node* next;
};
class Queue
{
	Queue();
	~Queue();
public:
	node* head;
	
	int pop();
	void push(int data);

	int peek();
	bool isEmpty();
	int getLength();
	void printQueue();

};
