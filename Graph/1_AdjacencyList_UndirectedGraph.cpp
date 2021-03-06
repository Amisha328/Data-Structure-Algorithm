#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void addEdge(vector<vector<int>> &graph, int u, int v )
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void printGraph(vector<vector<int>> &graph){
    for(int i = 0; i< graph.size(); i++)
    {
        cout<<i<<": ";
        for(int j = 0; j < graph[i].size(); j++)
              cout<<graph[i][j];
         cout<<endl;
    }
}
int main(){
    
    vector<vector<int>> adjacencyList;
    addEdge(adjacencyList, 0 , 1);
    addEdge(adjacencyList, 0 , 2);
    addEdge(adjacencyList, 1 , 2);
    addEdge(adjacencyList, 1 , 3);
    
    printGraph(adjacencyList);
    return 0;
}
