#include<stdio.h>
#include<stdlib.h>

int main() {

	int t,n,k,i,arr[100],j,front,rear,mid,flag=1;
	scanf("%d",&t);
	for(i=0;i<t;i++) {
		scanf("%d%d\n",&n,&k);
		for(j=0;j<n;j++) {
			scanf("%d",&arr[j]);
		}
		
		front = 0;
		rear = n-1;
		while(front<=rear) {
			mid = (front+rear)/2;
			if(arr[mid]==k) {
				flag=0;
				break;
			}
		else if(arr[mid]<k) {
			front = mid+1;
		}
		else if(arr[mid]>k) {
			rear = mid-1;
			}
		}
		if(flag==0) {
			printf("1\n");
		}
	else {
		printf("-1\n");
		}
		flag=1;
	}


}
