#include <bits/stdc++.h>

using namespace std;
static int t[100][100];

int knapsack(int w[],int v[],int wt,int n) {

    if(n==0 || wt==0) {
        return 0;
    }

    if(t[n][wt]!=-1) {
        return t[n][wt];
    }

    if(w[n-1]<=wt) {
        return t[n][wt] = max(v[n-1]+knapsack(w,v,wt-w[n-1],n-1),knapsack(w,v,wt,n-1));
    }
else if(w[n-1]>wt) {
    return t[n][wt] = knapsack(w,v,wt,n-1);
}

}

int main() {
    int n,w[100],v[100],wt;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>w[i]>>v[i];
    }
    cin>>wt;
    memset(t,-1,sizeof(t));

    cout<<"Maximum profit is "<<knapsack(w,v,wt,n)<<endl;

}

