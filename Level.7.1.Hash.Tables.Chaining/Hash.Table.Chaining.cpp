#include <iostream>
#include <random>
#include <list>

using namespace std;
int hashFunction(int key, const int MAX_HASH);
bool insert(list<int>[], const int MAX_HASH, int key);
bool search(list<int>[], const int MAX_HASH, int key);
bool remove(list<int>[], const int MAX_HASH, int key);

int main()
{
	const int MAX_HASH = 100;
	list<int> hashTable[MAX_HASH];
	random_device rdev;
	default_random_engine e(rdev());
	uniform_int_distribution<int> randNums(0, 10000);

	for (int i = 0; i < MAX_HASH * 10; i++)
	{
		insert(hashTable, MAX_HASH, randNums(e));
	}

	for (int i = 0; i < MAX_HASH / 2; i++)
	{
		if (search(hashTable, MAX_HASH, randNums(e)))
		{
			cout << "Number was found in the hash table!" <<endl;
		}
	}

	while (!remove(hashTable, MAX_HASH, randNums(e)))
	{
		cout << "Number removed!" << endl;
	}

	return 0;
}

int hashFunction(int key, const int MAX_HASH)
{
	return key%MAX_HASH;
}

bool insert(list<int> hashTable[], const int MAX_HASH, int key)
{
	int hashed = hashFunction(key, MAX_HASH);
	hashTable[hashed].push_back(key);
	return true;
}

bool search(list<int> hashTable[], const int MAX_HASH, int key)
{
	int hashed = hashFunction(key, MAX_HASH);
	
	for (auto item : hashTable[hashed])
	{
		if (item == key) return true;
	}
	return false;
}

bool remove(list<int> hashTable[], const int MAX_HASH, int key)
{
	int hashed = hashFunction(key, MAX_HASH);
	
	for (list<int>::iterator hashIter = hashTable[hashed].begin(); hashIter != hashTable[hashed].end(); hashIter++)
	{
		if (*hashIter == key)
		{
			hashTable[hashed].erase(hashIter);
			return true;
		}
	}
	return false;
}
