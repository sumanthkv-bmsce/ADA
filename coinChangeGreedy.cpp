#include<bits/stdc++.h>

using namespace std;

int main() {

    int value,noOfDenominations,ele;
    cin>>value>>noOfDenominations;

    vector<int> deno;

    //Accept the denominations
    for(int i=0;i<noOfDenominations;i++) {
        cin>>ele;
        deno.insert(deno.end(),ele);
    }

    //sort the values in descending order
    sort(deno.begin(),deno.end(),greater<int>());

    int count=0;
    int min = INT_MAX;
    int temp = value;
    for(int i=0;i<deno.size();i++) {
        temp = value;
        count = 0;
        for(int j=i;j<deno.size();j++) {
            if(temp>deno[j]) {
                count+= (temp/deno[j]);
                temp-=((temp/deno[j])*deno[j]);
            }
        }
        if(min>count) {
            min = count;
        }

    }

    cout<<"Minimum no of denominations are "<<min<<endl;
}