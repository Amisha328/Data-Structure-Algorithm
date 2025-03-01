// Course Schedule II
// Problem link:
// https://leetcode.com/problems/course-schedule-ii/
// https://practice.geeksforgeeks.org/problems/course-schedule/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& prerequisites) {
        vector<int> adj[N];
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> indegree(N, 0);
        
        for(int i = 0; i < N; i++)
            for(auto it: adj[i])
                indegree[it]++;
        
        vector<int> topo;
        queue<int> q;
        for(int i = 0; i < N; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
                
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adj[node]){
                if(--indegree[it] == 0)
                    q.push(it);
            }
        }
        if(topo.size() == N) return topo;
        else return {};
    }
};