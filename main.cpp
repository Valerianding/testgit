// C++ program for implementation of Heap Sort
#include <iostream>

using namespace std;

// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(int arr[], int n, int i)
{
    int parent,child;
    int temp = arr[i];
    for(parent = i; parent * 2 + 1 < n; parent = child){
        child  = parent * 2 + 1;
        if(child != n - 1 && arr[child] < arr[child+1]){
            child++;
        }
        if(temp >= arr[child]) break;
        else
            arr[parent] = arr[child];
    }
    arr[parent] = temp;
}

// Main function to do heap sort
void heapSort(int arr[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element
	// from heap
	for (int i = n - 1; i > 0; i--) {
	
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max haepify on the reduced heap
		heapify(arr, i, 0);
	}
}

// A utility function to print array of size n
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}



void merge(int arr[],int m,int n) {
    int i = 0, j = m, k = 0, buffer[n];
    while (i < m && j < n) {
        if (arr[i] < arr[j]) {
            buffer[k] = arr[i];
            i++;
        } else {
            buffer[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i < m) {
        buffer[k] = arr[i];
        i++;
        k++;
    }
    while (j < n) {
        buffer[k] = arr[j];
        j++;
        k++;
    }
    for (i = 0; i < k; i++) {
        arr[i] = buffer[i];
    }
}
// Driver code
int main()
{
	int arr[] = { 12,12,12,3,4,5,6,12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, n);

	cout << "Sorted array is \n";
	printArray(arr, n);
}