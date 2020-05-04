#include <bits/stdc++.h> 

using namespace std; 

void heap_one(int, int, int);
void sort(int, int); 

int main() 
{ 
	int arr[] = {10, 12, 15, 4, 2, 1}; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	sort(arr, n); 

	cout << "Sorted array is \n"; 
	printArray(arr, n); 
}

void printArray(int arr[], int n) 
{ 
	for (int i=0; i<n; ++i) 
		cout << arr[i] << " "; 
	cout << "\n"; 
} 

void sort(int arr[], int n) 
{ 
	for (int i = n / 2 - 1; i >= 0; i--) 
		heap_one(arr, n, i); 
	for (int i=n-1; i>0; i--) 
	{
		swap(arr[0], arr[i]); 
		heap_one(arr, i, 0); 
	} 
} 



void heap_one(int arr[], int n, int i) 
{ 
	int largest = i; 
	int l = 2*i + 1; 
	int r = 2*i + 2; 

	
	if (l < n && arr[l] > arr[largest]) 
		largest = l; 

	
	if (r < n && arr[r] > arr[largest]) 
		largest = r; 

	
	if (largest != i) 
	{ 
		swap(arr[i], arr[largest]); 
		heap_one(arr, n, largest); 
	} 
}
