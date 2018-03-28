#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
	node* prev;
};
void zipLists(node* & head1, node* & tail1, node* & head2, node* & tail2);
void unzipLists(node* & head1, node* & tail1, node* & head2, node* & tail2);
void printList(node* head);
int main()
{
	node* zHead = new node;
	zHead->next = nullptr;
	zHead->prev = nullptr;
	zHead->data = 0;

	node* zTail = zHead;

	const int NUM_NODES = 20;

	for (int i = 1; i < NUM_NODES; i++)
	{

		node* temp = new node;
		temp->next = nullptr;
		temp->prev = nullptr;
		zTail->next = temp;
		zTail->next->prev = zTail;;
		zTail = zTail->next;
		zTail->data = i;
	}
	node* unZHead = nullptr;
	node* unZtail = nullptr;
	bool zipped = true;

	while (true)
	{
		system("CLS");
		if (zipped)
		{
			printList(zHead);
			char unzip;
			cout << "Do you want to unzip the lists? y/n: ";
			cin >> unzip;
			if (unzip == 'y')
			{
				unzipLists(zHead, zTail, unZHead, unZtail);
				zipped = !zipped;
			}
			else
			{
				break;
			}
		}
		else
		{
			
			cout << "****LIST 1*****" << endl;
			printList(zHead);
			cout << "****LIST 2*****" << endl;
			printList(unZHead);
			char zip;
			cout << "Do you want to zip the lists? y/n: ";
			cin >> zip;
			if (zip == 'y')
			{
				zipLists(zHead, zTail, unZHead, unZtail);
				zipped = !zipped;
			}
			else
			{
				break;
			}
		}
	}

	//display list:


	system("PAUSE");


	return 0;

}

//zip two lists together head1 and tail1 will be the combined lists
//head2 and tail2 will be nullptr;
void zipLists(node * & head1, node * & tail1, node * & head2, node * & tail2)
{
	//start with list 1
	node* combinedHead = head1;
	node* combinedTail = combinedHead;
	head1 = head1->next;


	while (head1 != nullptr && head2 != nullptr)
	{

		//put in list 2 item
		combinedTail->next = head2;
		head2->prev = combinedTail;
		combinedTail = combinedTail->next;
		head2 = head2->next;

		//put in list 1 item
		combinedTail->next = head1;
		head1->prev = combinedTail;
		combinedTail = combinedTail->next;
		head1 = head1->next;
	}

	if (head1 != nullptr)
	{
		combinedTail->next = head1;
		head1->prev = combinedTail;
		while (combinedTail->next != nullptr)
		{
			combinedTail = combinedTail->next;
		}
	}
	else if (head2 != nullptr)
	{
		combinedTail->next = head2;
		head2->prev = combinedTail;
		while (combinedTail->next != nullptr)
		{
			combinedTail = combinedTail->next;
		}
	}

	head1 = combinedHead;
	tail1 = combinedTail;
	head2 = nullptr;
	tail2 = nullptr;


}

void unzipLists(node * & head1, node * & tail1, node * & head2, node *  & tail2)
{
	//set heads and current nodes.
	node* currNode1 = head1;
	head2 = head1->next;
	head2->prev = nullptr;
	node* currNode2 = head2;

	//while we haven't hit the end of either list.
	while (currNode1 != nullptr && currNode2 != nullptr)
	{
		//if list1 is empty, set the tail.
		if (currNode1->next == nullptr || currNode1->next->next == nullptr)
		{
			tail1 = currNode1;
			tail1->next = nullptr;
			currNode1 = currNode1->next;
		}
		else
		{
			//set the "prev" first, because this is not needed
			currNode1->next->next->prev = currNode1;
			//skip a node.
			currNode1->next = currNode1->next->next;
			//move to the next one.
			currNode1 = currNode1->next;
		}
		//duplicate as for list 1.
		if (currNode2->next == nullptr || currNode2->next->next == nullptr)
		{
			tail2 = currNode2;
			tail2->next = nullptr;
			currNode2 = currNode2->next;
		}
		else
		{
			currNode2->next->next->prev = currNode2;
			currNode2->next = currNode2->next->next;
			currNode2 = currNode2->next;
		}

	}
}


void printList(node * head)
{
	node* currNode = head;
	while (currNode != nullptr)
	{
		cout << currNode->data << endl;
		currNode = currNode->next;
	}
}
