#include <iostream>
#include <random>
#include <vector>

using namespace std;
//Examples taken from geeksforgeeks.org
void selectionSort(int array[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		//find the minimum element
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		//swap the latest minimum element with the first unsorted element
		int temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}
}

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

//Taken from Geeks for Geeks website
// A utility function to swap two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];    // pivot
	int i = (low - 1);  // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot)
		{
			i++;    // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low  --> Starting index,
high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int partition(vector<int>& v, int low, int high)
{
	//Grab the pivot
	int pivot = v[high];
	int pivotIndex = (low);
	//swap smaller to the left & bigger to the right
	for (int j = low; j < high; j++)
	{
		if (v[j] <= pivot)
		{
			int temp = v[j];
			v[j] = v[pivotIndex];
			v[pivotIndex] = temp;
			pivotIndex++;
		}
	}

	int temp = v[pivotIndex];
	v[pivotIndex] = v[high];
	v[high] = temp;
	return pivotIndex;

}

//modified from geeksforgeeks.com's algorithm.
void merge(vector<int> & v, int l, int m, int r)
{
	vector<int> left;
	vector<int> right;

	for (int i = l; i <= m; i++)
	{
		left.push_back(v[i]);
	}
	for (int i = m + 1; i <= r; i++)
	{
		right.push_back(v[i]);
	}

	int leftIndex = 0, rightIndex = 0, mergedIndex = l;
	while (leftIndex < left.size() && rightIndex < right.size())
	{
		if (left[leftIndex] <= right[rightIndex])
		{
			v[mergedIndex] = left[leftIndex];
			leftIndex++;
		}
		else
		{
			v[mergedIndex] = right[rightIndex];
			rightIndex++;
		}
		mergedIndex++;
	}
	while (leftIndex < left.size())
	{
		v[mergedIndex] = left[leftIndex];
		mergedIndex++;
		leftIndex++;
	}
	while (rightIndex < right.size())
	{
		v[mergedIndex] = right[rightIndex];
		mergedIndex++;
		rightIndex++;
	}

}
void mergeSort(vector<int> & v, int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		mergeSort(v, l, m);
		mergeSort(v, m + 1, r);

		merge(v, l, m, r);
	}
}
int main()
{
	random_device seed;
	default_random_engine engine(seed());
	uniform_int_distribution<int> randNum(0, 100);

	const int ARRAY_SIZE = 10;
	//int toBeSorted[ARRAY_SIZE];
	vector<int> toBeSorted;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		toBeSorted.push_back(randNum(engine));
		cout << toBeSorted[i] << " ";
	}
	//insertionSort(toBeSorted, ARRAY_SIZE);
	//selectionSort(toBeSorted, ARRAY_SIZE);
	//quickSort(toBeSorted, 0, ARRAY_SIZE - 1);
	int * p = new int;
	mergeSort(toBeSorted, 0, ARRAY_SIZE - 1);
	system("PAUSE");
	cout << endl << endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		cout << toBeSorted[i] << " ";
	}
	system("PAUSE");
	return 0;
}