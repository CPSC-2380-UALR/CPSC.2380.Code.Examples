#include <iostream>
using namespace std;

struct sNode
{
	int data;
	sNode* next;

};

struct dNode
{
	int data;
	dNode* next;
	dNode* prev;
};

void rotateRightSinglyLinkedList(sNode* & sHead);
void rotateRightDoublyLinkedList(dNode* & dHead, dNode*& tail);
void rotateLeftSinglyLinkedList(sNode* & sHead);
void rotateLeftDoublyLinkedList(dNode* & dHead, dNode*& tail);
void printList(sNode* sHead);
void printList(dNode* dHead);

int main()
{
	sNode* sHead = new sNode;
	sHead->data = 0;
	sHead->next = nullptr;

	dNode* dHead = new dNode;
	dHead->data = 0;
	dHead->next = nullptr;
	dHead->prev = nullptr;
	dNode* dTail = dHead;

	//create lists
	for (int i = 1; i < 10; i++)
	{
		//create singly linked list
		sNode* currSNode = sHead;
		while (currSNode->next != nullptr)
		{
			currSNode = currSNode->next;
		}
		sNode* sTemp = new sNode;
		sTemp->next = nullptr;
		currSNode->next = sTemp;
		currSNode = currSNode->next;
		currSNode->data = i;

		//create doubly linked list
		dNode* dTemp = new dNode;
		dTemp->next = nullptr;
		dTemp->prev = nullptr;
		dTemp->data = i;

		dTail->next = dTemp;
		dTail->next->prev = dTail;;
		dTail = dTail->next;
	}
	do
	{


		printList(sHead);
		printList(dHead);
		char whichList;
		cout << "Rotate a list (d) or (s): ";
		cin >> whichList;
		char whichWay;
		cout << "(l) or (r): ";
		cin >> whichWay;

		switch (whichList)
		{
		case 'd':
			if (whichWay == 'l')
			{
				rotateLeftDoublyLinkedList(dHead, dTail);
			}
			else
			{
				rotateRightDoublyLinkedList(dHead, dTail);
			}
			break;
		case 's':
			if (whichWay == 'l')
			{
				rotateLeftSinglyLinkedList(sHead);
			}
			else
			{
				rotateRightSinglyLinkedList(sHead);
			}
			break;

		default:
			break;
		}
		system("CLS");
	} while (true);
	return 0;
}

void rotateRightSinglyLinkedList(sNode* & sHead)
{
	sNode* currNode = sHead;
	//do nothing if empty list or one item list
	if (currNode != nullptr && currNode->next != nullptr)
	{
		while (currNode->next->next != nullptr)
		{
			currNode = currNode->next;
		}
		currNode->next->next = sHead;
		sHead = currNode->next;
		currNode->next = nullptr;
	}
}
void rotateRightDoublyLinkedList(dNode* & dHead, dNode* & tail)
{
	dNode* currNode = dHead;

	if (currNode != nullptr && currNode->next != nullptr)
	{
		//connect tail and head
		tail->next = dHead;
		dHead->prev = tail;

		//back up tail and head
		tail = tail->prev;
		dHead = dHead->prev;

		//disconnect new tail and head
		tail->next = nullptr;
		dHead->prev = nullptr;
	}
}
void rotateLeftSinglyLinkedList(sNode* & sHead)
{
	sNode* currNode = sHead;
	//do nothing if empty list or one item list
	if (currNode != nullptr && currNode->next != nullptr)
	{
		while (currNode->next != nullptr)
		{
			currNode = currNode->next;
		}
		//point last item to first
		currNode->next = sHead;
		//move the head along one.
		sHead = sHead->next;
		//disconnect end from head
		currNode->next->next = nullptr;
	}
}
void rotateLeftDoublyLinkedList(dNode* & dHead, dNode*& tail)
{
	//ignore empty list or one item list.
	if (dHead != nullptr && dHead->next != nullptr)
	{
		//connect tail and head
		tail->next = dHead;
		dHead->prev = tail;

		//move tail and head
		tail = tail->next;
		dHead = dHead->next;

		//disconnect new tail and head
		tail->next = nullptr;
		dHead->prev = nullptr;
	}
}

void printList(sNode * sHead)
{
	cout << "******Singly Linked List*****" << endl;
	sNode* currNode = sHead;
	int i = 1;
	while (currNode != nullptr)
	{
		cout << "Node " << i << ": " << currNode->data << endl;
		i++;
		currNode = currNode->next;
	}
}

void printList(dNode * dHead)

{
	cout << "******Doubly Linked List*****" << endl;
	dNode* currNode = dHead;
	int i = 1;
	while (currNode != nullptr)
	{
		cout << "Node " << i << ": " << currNode->data << endl;
		i++;
		currNode = currNode->next;
	}
}
