#include <iostream>
#include <random>
#include <list>

struct node
{
	int data;
	int hashIndex;
	bool empty;
	node* next;
	node()
	{
		data = 0;
		empty = false;
		next = nullptr;
		hashIndex = 0;
	}
	node(int key, int hashed): node()
	{
		data = key;
		hashIndex = hashed;
	}
	
};
using namespace std;
int hashFunction(int key, const int MAX_HASH);
bool insert(node* [], bool alwaysEmpty[], const int MAX_HASH, int key);
bool search(node* [], bool alwaysEmpty[], const int MAX_HASH, int key);
bool remove(node* [], bool alwaysEmpty[], const int MAX_HASH, int key);
void printTable(node*[], const int MAX_HASH);

int main()
{
	const int MAX_HASH = 100;
	bool alwaysEmpty[MAX_HASH];
	node*  hashTable[MAX_HASH];
	for (int i = 0; i < MAX_HASH; i++)
	{
		alwaysEmpty[i] = true;
		hashTable[i] = nullptr;
	}
	
	random_device rdev;
	default_random_engine e(rdev());
	uniform_int_distribution<int> randNums(0, 10000);

	for (int i = 0; i < MAX_HASH; i++)
	{
		insert(hashTable, alwaysEmpty, MAX_HASH, randNums(e));
	}
	char command;
	int key = 0;
	do
	{
		printTable(hashTable, MAX_HASH);
		cout << "search key: ";
		cin >> key;

		if (search(hashTable, alwaysEmpty, MAX_HASH, key))
		{
			cout << "Number was found in the hash table!" << endl;
		}

		cout << "remove key: ";
		cin >> key;
		if (remove(hashTable, alwaysEmpty, MAX_HASH, key))
		{
			cout << "Number removed!" << endl;
		}

		cout << "Search & remove again? (y/n): ";
		cin >> command;
	} while (command != 'n');

	return 0;
}

int hashFunction(int key, const int MAX_HASH)
{
	return key%MAX_HASH;
}

bool insert(node*  hashTable[], bool alwaysEmpty[], const int MAX_HASH, int key)
{
	int hashed = hashFunction(key, MAX_HASH);
	node* currNode = hashTable[hashed];
	node* prevNode = nullptr;
	node* toInsert = new node(key, hashed);
	if (currNode== nullptr)
	{
		hashTable[hashed] = toInsert;
		alwaysEmpty[hashed] = false;

	}
	else 
	{
		while (currNode != nullptr && currNode->empty == false)
		{
			prevNode = currNode;
			currNode = currNode->next;
		}
		int insertIndex = 0;
		if (currNode == nullptr)
		{
			
			while (insertIndex < MAX_HASH && alwaysEmpty[insertIndex] == false )
			{
				insertIndex++;
			}
			if (insertIndex >= MAX_HASH)
			{
				return false;
			}
			
		}
		else
		{
			insertIndex = currNode->hashIndex;
			prevNode->next = currNode->next;
			delete currNode;
		}
		
		toInsert->next = prevNode->next;
		prevNode->next = toInsert;

		hashTable[insertIndex] = toInsert;
		alwaysEmpty[insertIndex] = false;

		toInsert->hashIndex = insertIndex;
	}
	return true;
}

bool search(node*  hashTable[], bool alwaysEmpty[], const int MAX_HASH, int key)
{
	int hashed = hashFunction(key, MAX_HASH);
	node* currNode = hashTable[hashed];

	while (currNode != nullptr && (currNode->data != key || currNode->empty == true))
	{
		currNode = currNode->next;
	}
	if (currNode!=nullptr && currNode->data == key && currNode->empty == false)
		return true;
	
	return false;
}

bool remove(node*  hashTable[], bool alwaysEmpty[], const int MAX_HASH, int key)
{
	int hashed = hashFunction(key, MAX_HASH);
	node* currNode = hashTable[hashed];

	while (currNode != nullptr && (currNode->data != key || currNode->empty == true))
	{
		currNode = currNode->next;
	}
	if (currNode != nullptr && currNode->data == key && currNode->empty == false)
	{
		currNode->empty = true;
		return true;
	}
	else
	{
		return false;
	}
}

void printTable(node * hashTable[], const int MAX_HASH)
{
	for (int i = 0; i < MAX_HASH; i++)
	{
		if (hashTable[i] != nullptr)
		{
			cout << "hash[" << i << "]: data(" << hashTable[i]->data << "), empty(";
			if (hashTable[i]->empty)
			{
				cout << "true)" << endl;
			}
			else
			{
				cout << "false)" << endl;
			}
		}
	}
}
