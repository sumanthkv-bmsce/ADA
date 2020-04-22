#include <bits/stdc++.h>

using namespace std;
int V;

void addEdge(vector<pair<int,int>> adj[],int u,int v,int w) {
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));

}


int minTree(int key[],bool present[]) {
    int min = INT_MAX,min_index;
    for(int i=0;i<V;i++) {
        if(present[i]==false && min>key[i]) {
            min_index = i;
            min = key[i];
        }
    }

    return min_index;
}


void findMST(vector<pair<int,int>> adj[]) {
    int key[10];
    int parent[10];
    bool present[10];
    parent[0] = -1;

    for(int i=0;i<V;i++) {
        key[i] = INT_MAX;
        present[i] = false;
    }

    key[0] = 0;

    for(int count=0;count<V;count++) {

        int u = minTree(key,present);
        present[u] = true;
        for(auto j = adj[u].begin();j!=adj[u].end();j++) {
            if(present[j->first] == false && key[j->first]>j->second) {
                key[j->first] = j->second;
                parent[j->first] = u;
            }
        }

    }
    int sum = 0;

    for(int i=0;i<V;i++) {
        cout<<i<<" "<<parent[i]<<" "<<key[i]<<endl;
        sum+= key[i];
    }

    cout<<"Min span tree weightage is "<<sum<<endl;

}

int main() {
    int a,b,wt,e;
    cin>>V>>e;
    vector<pair<int,int>> adj[V];
    for(int i=0;i<e;i++) {
        cin>>a>>b>>wt;

        adj[a].push_back(make_pair(b,wt));
        adj[b].push_back(make_pair(a,wt));
    }
    findMST(adj);

}






