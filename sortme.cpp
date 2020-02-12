#include<bits/stdc++.h>
#include<cstdlib> 
#include<ctime>
#include <experimental/random>
using namespace std;

int* sort(int[],int);

int main() {
	int n,i,*a,temp;
	cout<<"Enter n: "<<endl;
	cin>>n;
	srand(time(NULL));
	
	for(int i=0;i<n;i++) {
	int random_number = experimental::randint(1, 10000);
	        a[i] = random_number;
	}
	auto start = chrono::steady_clock::now();
	
	a = sort(a,n);
	sort(a,a+n);
	
	for(int i=0;i<n;i++) {
	        //cout<<a[i]<<" ";
	  }
	  auto end = chrono::steady_clock::now();
	  auto diff = end - start;
	  
	 cout << chrono::duration <double,milli> (diff).count() << " ms" << endl;
	  return 0;
	
}

int* sort(int a[],int n) {
	int temp;
	for(int i=0;i<n;i++) {
	        for(int j=i+1;j<n;j++) {
	                if(a[i]>a[j]) {
	                        temp = a[i];
	                        a[i] = a[j];
	                        a[j] = temp;
	                   }
	             }
	        }
	        return a; 
}







