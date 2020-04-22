#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int>> adj[100];

bool checkCycle(vector<int> temp[],int tVis[],int par,int v) {
    tVis[v] = 1;

    for(auto child:temp[v]) {
        if(tVis[child]==0) {
            if(checkCycle(temp,tVis,v,child)==true) {
                return true;
            }
        }
        else if(child!=par) {
            return true;
        }
    }
    return false;
}

int main() {

    int n,e,a,b,wt;
    cin>>n>>e;
    int wtArr[n+1];
    int vis[n+1];
    for(int i=0;i<e;i++) {

        cin>>a>>b>>wt;
        wtArr[i] = wt; 
        vis[i]= 0;
        adj[a].push_back(make_pair(b,wt));
        adj[b].push_back(make_pair(a,wt));

    }

    sort(wtArr,wtArr+n);
    vector<int> temp[n+1];
    int tVis[n+1];

    int sum = 0,count=0;
    bool flag=true;
    for(int i=0;i<e;i++) {
        int wtEle = wtArr[i];
        for(int j=0;j<n;j++) {
            flag=true;
            for(auto k=adj[j].begin();k!=adj[j].end();k++) {
                if((k->second==wtEle)) {

                    for(auto t=temp[j].begin();t!=temp[j].end();t++) {
                        if(*t==(k->first)) {
                            flag=false;
                            break;
                        }
                    }
                    if(flag==false) {
                        continue;
                    }
                    

                    vis[j] = 1;
                    vis[k->first] = 1;
                    temp[j].push_back(k->first);
                    temp[k->first].push_back(j);
                    tVis[j] = 0;
                    tVis[k->first] = 0;
                    int ss = sizeof(tVis)/sizeof(tVis[0]);

                    for(int z=0;z<ss;z++) {
                        tVis[z] = 0;
                    }

                    bool checker = checkCycle(temp,tVis,j,k->first);
                    if(checker==true) {
                        temp[j].pop_back();
                        temp[k->first].pop_back();
                    } 
                    else {
                        sum+=wtEle;
                        cout<<"Edge from "<<j<<" to "<<k->first<<" with weight "<<wtEle<<endl;
                        count++;
                    }

                }
            }
        }
        if(count==n-1) {
            break;
        }

    }   
    cout<<"\nWeight of a Minimum spanning tree is "<<sum<<endl;
}