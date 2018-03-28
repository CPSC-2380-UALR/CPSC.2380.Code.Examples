#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
	Stack*  myStack = new Stack;
	const int QUEUE_SIZE = 10;
	cout << "Empty Stack? " << myStack->isEmpty() << endl;
	for (int i = 0; i < QUEUE_SIZE; i++)
	{
		myStack->push(i);
	}
	cout << "Empty Stack after pushes? " << myStack->isEmpty() << endl;
	cout << "Stack Content after initial creation:" << endl;
	myStack->printStack();

	cout << myStack->pop() << endl;
	cout << "Stack after pop: " << endl;
	myStack->printStack();
	cout << myStack->peek() << endl;
	cout << "Stack after peek: " << endl;
	myStack->printStack();
	system("PAUSE");
	return 0;
}


