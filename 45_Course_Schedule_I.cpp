// Course Schedule I
// Problem link:
// https://leetcode.com/problems/course-schedule/
// https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1
// https://www.codingninjas.com/codestudio/problem-details/prerequisite-task_982936

#include<bits/stdc++.h>
using namespace std;

// Detch Cycle - DFS Approach
class Solution {
public:
    bool DFSRec(vector<vector<int>>& adj, int s, bool visited[], bool recSt[])
    {
        visited[s] = true;
        recSt[s] = true;
        
        for(int i : adj[s])
        {
            if(!visited[i] && DFSRec(adj, i, visited, recSt))
                return true;
            else if(recSt[i])
                return true;
        }
        
        recSt[s] = false;
        return false;
    }
    
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>>adj(V);
        
        // create adj list
        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        bool visited[V+1], recSt[V+1];
        
        for(int i = 0; i < V; i++)
        {
            visited[i] = false;
            recSt[i] = false;
        }
        
        for(int i = 0; i < V; i++)
        {
            // if there is a cycle we cannot finish all courses.
            if(!visited[i] && DFSRec(adj, i, visited, recSt))
                return false;
        }
        
        return true; // if there is no cycle all courses can be finished
        
    }
};

// Topological Sort - Kahn's Algorithm - BFS
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<int> adj[N];
	    for(auto it: prerequisites){
	        adj[it.first].push_back(it.second);
	    }
	    
	    int indegree[N] = {0};
	    for(int i = 0; i < N; i++)
	    {
	        for(auto it: adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i = 0; i < N; i++)
	        if(indegree[i] == 0)
	            q.push(i);
	   
	    int cnt = 0;
	    while(!q.empty()){
	        int node = q.front();
	        cnt++;
	        q.pop();
	        for(auto it: adj[node]){
	            if(--indegree[it] == 0)
	                q.push(it);
	        }
	    }
	    
	    if(cnt == N) return true;
	    else return false;
	}
};