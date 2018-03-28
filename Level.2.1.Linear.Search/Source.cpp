#include <iostream>
using namespace std;

int linearSearch(int array[], int size, int searchKey) {

	for (int i = 0; i<size; i++) {
		if (searchKey == array[i]) {
			return i;
		}
	}
	return -1;

}
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;

		// If the element is present at the middle itself
		if (arr[mid] == x)  return mid;

		// If element is smaller than mid, then it can only be present
		// in left subarray
		if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);

		// Else the element can only be present in right subarray
		return binarySearch(arr, mid + 1, r, x);
	}

	// We reach here when element is not present in array
	return -1;
}


int main()
{
	const int SIZE = 5;
	int myArray[5];
	for (int i = 0; i < SIZE; i++)
	{
		myArray[i] = i;
	}

	int searchKey = -1;
	cout << "What do you want ot search for: ";
	cin >> searchKey;

	//int response = linearSearch(myArray, SIZE, searchKey);
	int response = binarySearch(myArray, 0, SIZE-1, searchKey)+1;
	if (response == -1)
	{
		cout << searchKey << " was not found in the array." << endl;
	}
	else
	{
		cout << searchKey << " was found at slot " << response << " in the array" << endl;
	}
	system("PAUSE");

	return 0;
}