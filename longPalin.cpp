#include<bits/stdc++.h>

using namespace std;
int t[100][100];

int longPalin(string s1,string s2,int n,int m) {

    for(int i=0;i<n+1;i++) {
        t[i][0] = 0;
    }

    for(int i=0;i<m+1;i++) {
        t[0][i] = 0;
    }

    for(int i=1;i<n+1;i++) {
        for(int j=1;j<m+1;j++) {
            if(s1[i]==s2[j]) {
                t[i][j] = 1+t[i-1][j-1];
            }
            else {
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    }

    return t[n][m];

}

int main() {
    string s1;
    cin>>s1;
    string s2 = s1;
    reverse(s1.begin(),s1.end());
    memset(t,-1,sizeof(t));
    int ele = longPalin(s2,s1,s1.length(),s1.length());
    cout<<ele<<endl;
}