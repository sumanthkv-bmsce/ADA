#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,c,k,s[100],f[100],min,sum;
    cin>>n>>c>>k;

    for(int i=0;i<c;i++) {
        cin>>s[i]>>f[i];
    }

    for(int i=0;i<c;i++) {
        min = i;
        for(int j = i+1;j<c;j++) {
            if(s[i]>s[j]) {
                min = j;
            }
        }
        swap(s[i],s[min]);
        swap(f[i],f[min]);
    }

    sum = 0;

    for(int i=0;i<c;i++) {
        sum= sum + (f[i]-s[i]+1);
        
    }

    cout<<sum<<endl;
    if(sum>n) {
        cout<<"Bad"<<endl;
    }
    else {
        cout<<"Good"<<endl;
    }




}