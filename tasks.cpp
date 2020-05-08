#include <bits/stdc++.h>
using namespace std;
// Converts list into graph
vector<unordered_set<int> > make_graph(int Tasks, vector<pair<int, int> >& dependencies) {
   vector<unordered_set<int> > graph(Tasks);
   for (auto pre : dependencies)
      graph[pre.second].insert(pre.first);
   return graph;
}
//to check if all the nodes are visited
bool cycle(vector<unordered_set<int> >& graph, int node, vector<bool>& onway, vector<bool>& visited) {
   if (visited[node])
      return false;
   onway[node] = visited[node] = true;
   for (int near : graph[node]) {
      if (onway[near] || cycle(graph, near, onway, visited))
         return true;
   }
   return onway[node] = false;
}
//to check if all the tasks can be completed
bool canFinish(int Tasks, vector<pair<int, int> >& dependencies) {
   vector<unordered_set<int>>graph = make_graph(Tasks, dependencies);
   vector<bool> onway(Tasks, false), visited(Tasks, false);
   for (int i = 0; i < Tasks; i++) {
      if (!visited[i] && cycle(graph, i, onway, visited))
         return false;
   }
   return true;
}
int main() {
   int Tasks = 6;
   vector<pair<int, int >> dependencies;
   dependencies.push_back(make_pair(1, 0));
   dependencies.push_back(make_pair(2, 1));
   dependencies.push_back(make_pair(3, 2));
   dependencies.push_back(make_pair(5, 3));
   dependencies.push_back(make_pair(4, 5));
   if (canFinish(Tasks, dependencies)) {
      cout << "True";
   }
   else {
      cout << "False";
   }
   return 0;
}
