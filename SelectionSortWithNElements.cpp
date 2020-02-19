#include <iostream>
using namespace std;

void selectSort(int*,int);
void kLargestElements(int*,int,int);
int main() {
    int arr[100],n,i,j,min,temp,k;
    cin>>n>>k;
	for(i=0;i<n;i++) {
	    cin>>arr[i];
	}

	selectSort(arr,n);

	kLargestElements(arr,n,k);


}


void selectSort(int arr[],int n) {
    int i,j,min,temp;
    for(i=0;i<n-1;i++) {
	    min = i;
	    for(j=i+1;j<n;j++) {
	        if(arr[min]>arr[j]) {
	            min = j;
	        }
	    }

	    temp = arr[min];
	    arr[min] = arr[i];
	    arr[i] = temp;

	}
	cout<<"The sorted array elements are:\n";
	for(i=0;i<n;i++) {
	    cout<<arr[i]<<" ";
	}
	cout<<endl;


}

void kLargestElements(int arr[],int n,int k) {
    int i;
    cout<<"K largest elements are:\n";
    for(i=n-k;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}




