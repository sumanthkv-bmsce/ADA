#include<stdio.h>
#include<stdlib.h>

int main() {
	int i,n,arr[100],j,num;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		arr[i] = i;
	}
	
for(i=2;i<=n;i++) {
	num = i*i;
	for(j=num;j<=n;j++) {
		if(num>n) {
			break;
		}
	else {
		arr[num] = 0;
		num+=i;
		}
	}
}

	for(i=2;i<=n;i++) {
		if(arr[i]==0) {
			continue;
		}
		printf("%d ",arr[i]);
	}
	printf("\n");
}
			
			
		
		
	
