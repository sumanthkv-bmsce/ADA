#include <iostream>
#include <list>

using namespace std;

class Graph {
private:
    int V;
    list<int> *adj;

public:
    Graph(int v);
    void addEdge(int v,int w);
    void BFS(int s);

};

Graph::Graph(int v) {
    V = v;
    adj = new list<int>[v];
}

void Graph::addEdge(int v,int w) {
    adj[v].push_back(w);
}


void Graph::BFS(int s) {
    bool *visited = new bool[V];
    for(int i=0;i<V;i++) {
        visited[i] = false;
    }

    list<int>queue;

    visited[s] = true;
    queue.push_back(s);

    while(!queue.empty()) {
        s = queue.front();
        queue.pop_front();

        cout<<"checking adjacent vertices for vertex"<<s<<endl;
        for(auto i = adj[s].begin();i!=adj[s].end();i++) {
            if(!visited[*i]) {
                cout<<"Visit and enqueue"<<*i<<endl;
                visited[*i] = true;
                queue.push_back(*i);
            }
        }


    }
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

    g.BFS(0);

    return 0;

}
