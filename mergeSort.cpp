#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void mergeSort(int [],int,int);
void merge(int[],int,int,int);

int main() {
	
	int arr[100],n;
	cin>>n;
	for(int i=0;i<n;i++) {
	    cin>>arr[i];
	}
	
	mergeSort(arr,0,n-1);
	for(int i=0;i<n;i++) {
	    cout<<arr[i]<<" ";
	}
	
	
}

void mergeSort(int arr[],int low,int high) {
    int mid;
    if(low<high) {
        mid = (low+high)/2;
        
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

void merge(int arr[],int low,int mid,int high) {
    int n1,n2,i,j,l[100],r[100],k;
    n1 = (mid-low)+1;
    n2 = (high-mid);
    
    for(int i=0;i<n1;i++) {
        l[i] = arr[low+i];
    }
    
    for(int i=0;i<n2;i++) {
        r[i] = arr[mid+1+j];
    }
    
    i=0;
    j=0;
    k = low;
    
    while(i<n1 && j<n2) {
        if(l[i]<r[i]) {
            arr[k] = l[i];
            i++;
        }
        else {
            arr[k] = r[j];
            j++;
        }
        k++;
    }
    
    while(i<n1) {
        arr[k++] = l[i++];
    }
    
    while(j<n2) {
        arr[k++] = r[j++];
    }
    
    
}






