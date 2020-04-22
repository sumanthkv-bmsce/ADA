#include <bits/stdc++.h>

using namespace std;
int t[100][100];
bool sumEqual(int arr[],int n,int sum1,int sum2) {
    if(n==0 && sum1!=sum2) {
        return 0;
    } 

    if(sum1!=0 && sum2!=0 && sum1==sum2 && n==0) {
        return 1;
    }

    return t[n][sum1] = sumEqual(arr,n-1,sum1+arr[n-1],sum2)|| sumEqual(arr,n-1,sum1,sum2+arr[n-1]);
}



int main() {
    int arr[100],n;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    memset(t,-1,sizeof(t));

    cout<<sumEqual(arr,n,0,0)<<endl;
}