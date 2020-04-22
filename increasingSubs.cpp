#include<bits/stdc++.h>

using namespace std;

void LICS(vector<int> &v,vector<int> &lic) {

    for(int i=1;i<v.size();i++) {
        for(int j=0;j<=i-1;j++) {
            if(v[i]>v[j]) {
                lic[i] = max(1+lic[j],lic[i]);
            }
        }
    }
}

int main() {

    int n,ele;
    //Accept the size
    cin>>n;
    vector<int> v;
    vector<int> lic;    //to store the specific count values
    for(int i=0;i<n;i++) {
        cin>>ele;
        v.insert(v.end(),ele);
        lic.insert(lic.end(),1);  //storing all the positions with value 1
    }

    LICS(v,lic);  

    cout<<"Length of the longest increasing subsequence is "<<lic.back()<<endl;

}