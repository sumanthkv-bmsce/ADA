#include<stdio.h>
#include<stdlib.h>

int main() {
	int n,i,a[100],key,low,high,mid,first,last,flag=1,ele,index;
	printf("Enter n; ");
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	printf("Enter key; ");
	scanf("%d",&key);
	low = 0;
	high = n-1;
	while(low<=high) {
		mid = (low+high)/2;
		index = mid;
		first = mid;
		if(a[mid]==key) {
			if(a[mid-1]==key) {
				mid--;
				while(a[mid]==key) {
					mid--;
				}
				if(mid<index) {
					first = mid+1;
				}
			else {
				first = mid;
			 }
			}
			
			mid = index;
			last = mid;
			if(a[mid+1]==key) {
				mid++;
				while(a[mid]==key) {
					mid++;
				}
				if(mid>index) {
					last = mid-1;
				}
			else {
				last = mid;
			 }
			}
			flag=0;
			break;
		}
	else if(a[mid]>key) {
			high = mid-1;
		}
	else if(a[mid]<key) {
			low = mid+1;
		}
	}
	
	if(flag==0) {
		printf("first is %d\nlast is %d\ncount is %d\n",first,last,(last-first+1));
	}
else {
	printf("Invalid\n");
}
	
	return 0;
}
	
		
			
				
				
	
		
		
