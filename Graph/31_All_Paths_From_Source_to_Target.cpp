// All Paths From Source to Target
// Problem link:
// https://leetcode.com/problems/all-paths-from-source-to-target/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int> &ans, vector<vector<int>> &res){
        if(node == adj.size()-1)  res.push_back(ans);  // when reach the last node stop the traversal
        
        for(auto &it: adj[node]){
            ans.push_back(it);
            dfs(it, adj, ans, res); // dfs to visit the adjacent nodes
            ans.pop_back();  // back-tracking
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(0);
        dfs(0, graph, temp, ans);
        return ans;
    }
};