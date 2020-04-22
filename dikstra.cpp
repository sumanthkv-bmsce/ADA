#include <bits/stdc++.h>
#define V 9
using namespace std;
int getMin(int[],bool[]);

void addEdge(vector<pair<int,int>> adj[],int u,int v,int w) {
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}

void findDikstra(vector<pair<int,int>> adj[]) {
    int  s[100];
    bool q[100];
    int p[100];
    for(int i=0;i<V;i++) {
        s[i] = INT_MAX;
        q[i] = false;
    }

    s[0] = 0;
    p[0] = -1;
    int u;
    for(int i=0;i<V;i++) {
        u = getMin(s,q);
        
        for(auto j = adj[u].begin();j!=adj[u].end();j++) {
            if(q[j->first]==false && s[j->first] > s[u]+(j->second)) {
                s[j->first] = s[u]+j->second;
                p[j->first] = u;
            }
        }
        q[u] = true;
        
    }

    for(int i=0;i<V;i++) {
        cout<<s[i]<<" "<<p[i]<<endl;
    }
}



int main() {
    vector<pair<int,int>> adj[V];

    addEdge(adj,0,1,4);
    addEdge(adj,0,7,8);
    addEdge(adj,1,2,8);
    addEdge(adj,1,7,11);
    addEdge(adj,2,3,7);
    addEdge(adj,2,5,4);
    addEdge(adj,2,8,2);
    addEdge(adj,3,4,9);
    addEdge(adj,3,5,14);
    addEdge(adj,4,5,10);
    addEdge(adj,5,6,2);
    addEdge(adj,6,7,1);
    addEdge(adj,6,8,6);
    addEdge(adj,7,8,7);

    findDikstra(adj);
    /*for(int i=0;i<V;i++) { 
        for(auto j = adj[i].begin();j!=adj[i].end();j++) {
            cout<<j->second;
        }
        cout<<endl;
    }*/


}



int getMin(int key[],bool present[]) {
    int min = INT_MAX,min_index;
    for(int i=0;i<V;i++) {
        if(present[i]==false && min>key[i]) {
            min_index = i;
            min = key[i];
        }
    }

    return min_index;
}