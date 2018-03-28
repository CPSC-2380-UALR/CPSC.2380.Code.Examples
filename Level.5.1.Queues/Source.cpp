#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
	Queue*  myQueue = new Queue;
	const int QUEUE_SIZE = 10;
	cout << "Empty Queue? " << myQueue->isEmpty() << endl;
	for (int i = 0; i < QUEUE_SIZE; i++)
	{
		myQueue->push(i);
	}
	cout << "Empty Queue after pushes?" << myQueue->isEmpty() << endl;
	cout << "Queue Content after initial creation:" << endl;
	myQueue->printQueue();

	cout << myQueue->pop() << endl;
	cout << "Queue after pop: " << endl;
	myQueue->printQueue();
	cout << myQueue->peek() << endl;
	cout << "Queue after peek: " << endl;
	myQueue->printQueue();
	system("PAUSE");
	return 0;
}


