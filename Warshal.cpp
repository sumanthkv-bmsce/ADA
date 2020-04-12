#include <bits/stdc++.h> 
using namespace std; 
#define V 4  
#define MAX 99999  
  

void printSolution(int dist[][V])  
{  
    cout<<"The following matrix shows the shortest distances"
            " between every pair of vertices \n";  
    for (int i = 0; i < V; i++)  
    {  
        for (int j = 0; j < V; j++)  
        {  
            if (dist[i][j] == MAX)  
                cout<<"MAX"<<"     ";  
            else
                cout<<dist[i][j]<<"     ";  
        }  
        cout<<endl;  
    }  
}  
void algo (int graph[][V])  
{  
    int dist[V][V], i, j, k; 
    for (i = 0; i < V; i++)  
        for (j = 0; j < V; j++)  
            dist[i][j] = graph[i][j]; 
    for (k = 0; k < V; k++)  
    { 
        for (i = 0; i < V; i++)  
        { 
            for (j = 0; j < V; j++)  
            { 
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }  
        }  
    }
    printSolution(dist);  
}  
  

  

int main()  
{  
    int graph[V][V] = { {0, 5, MAX, 10},{MAX, 0, 3, MAX},{MAX, MAX, 0, 1},  {MAX, MAX, MAX, 0} };  
    algo(graph);  
    return 0;  
}  
