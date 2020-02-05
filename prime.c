#include<stdio.h>
int gcd(int ,int);

int main() {
	int m,n,val;
	scanf("%d%d",&m,&n);
	val = gcd(m,n);
	printf("%d",val);
	return 0;
}

int gcd(int m,int n) {

	if(m==0) {
		return n;
	}
	if(n==0) {
		return m;
	}
	if(m>n) {
		return gcd(m-n,n);
	}
	if(n>m) {
		return gcd(m,n-m);
	}
	
}
