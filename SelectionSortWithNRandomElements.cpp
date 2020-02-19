#include<bits/stdc++.h>
#include<cstdlib>
#include<ctime>
#include<experimental/random>
using namespace std;

void selectSort(int*,int);

int main() {
    int arr[100000],n,i,j,min,temp,k;
    cin>>n;
	for(i=0;i<n;i++) {
	    int random_number = experimental::randint(1, 100000);
	    arr[i] = random_number;

	}
	auto start = chrono::steady_clock::now();
	selectSort(arr,n);
	auto end = chrono::steady_clock::now();
	  auto diff = end - start;

	 cout << chrono::duration <double,milli> (diff).count() << " ms" << endl;


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

}





