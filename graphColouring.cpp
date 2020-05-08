#include<stdio.h> 
#include<stdbool.h> 

int V;

void print(int color[]); 
bool find_out (int v, bool graph[V][V], int color[], int c) 
{ 
	for (int i = 0; i < V; i++) 
		if (graph[v][i] && c == color[i]) 
			return false; 
	return true; 
} 

bool graphColoringUtil(bool graph[V][V], int m, int color[], int v) 
{ 
	
	if (v == V) 
		return true; 

	for (int c = 1; c <= m; c++) 
	{ 
		
		if (find_out(v, graph, color, c)) 
		{ 
		color[v] = c; 

		if (graphColoringUtil (graph, m, color, v+1) == true) 
			return true; 

		color[v] = 0; 
		} 
	} 

	return false; 
} 

bool graphColoring(bool graph[V][V], int m) 
{ 
	
	int color[V]; 
	for (int i = 0; i < V; i++) 
	color[i] = 0; 

	if (graphColoringUtil(graph, m, color, 0) == false) 
	{ 
	printf("Solution does not exist"); 
	return false; 
	} 

	print(color); 
	return true; 
} 

void print(int color[]) 
{ 
	printf("Solution Exists:"
			" Following are the assigned colors \n"); 
	for (int i = 0; i < V; i++) 
	printf(" %d ", color[i]); 
	printf("\n"); 
} 

int main() 
{ 
    int m;
    cin>>V;
    bool graph[V+1][V+1];
    
    for(int i=0;i<V;i++) {
        for(int j=0;j<V;j++) {
            cin>>graph[i][j];
        }
    }

    cin>>m;
	graphColoring (graph, m); 
	return 0; 
} 
