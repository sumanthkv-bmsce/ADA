#include <iostream>
#include <list>

using namespace std;

class Graph {
private:
    int V;
    list<int> *adj;
    void DFS_helper(int s,bool *visited);

public:
    Graph(int v);
    void addEdge(int v,int w);
    void DFS(int s);

};

Graph::Graph(int v) {
    V = v;
    adj = new list<int>[v];
}

void Graph::addEdge(int v,int w) {
    adj[v].push_back(w);
}

void Graph::DFS_helper(int s,bool *visited) {
    cout<<"Visiting node"<<s<<endl;
    visited[s] = true;

    for(auto i=adj[s].begin(); i!=adj[s].end();i++) {
        if(!visited[i]) {
            cout<<"Going to vertex"<<*i<<"from"<<s<<endl;
            DFS_helper(*i,visited);
        }
    }

}

void Graph::DFS(int s) {
    bool *visited = new bool[V];
    for(int i=0;i<V;i++) {
        visited[i] = false;
    }

    DFS_helper(s,visited);
}

int main()
{
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,2);

    g.addEdge(1,0);
    g.addEdge(1,3);
    g.addEdge(1,4);

    g.addEdge(2,0);
    g.addEdge(2,4);

    g.addEdge(3,1);
    g.addEdge(3,4);
    g.addEdge(3,5);

    g.addEdge(4,1);
    g.addEdge(4,2);
    g.addEdge(4,3);
    g.addEdge(4,5);

    g.addEdge(5,3);
    g.addEdge(5,4);

    g.DFS(0);

    return 0;

}
