// Most Stones Removed with Same Row or Column
// Problem link:
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
// https://www.codingninjas.com/codestudio/problem-details/most-stones-removed-with-same-row-or-column_1376597

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public: 
    void  dfs(vector<int>&visited,vector<vector<int>>& stones,int index){

        // make it visited.
        visited[index] =1;

        // traversal.
        for(int i=0;i<stones.size();i++){
            // if not visited and are in same group ,call dfs
            if(!visited[i] && (stones[index][0] == stones[i][0] || stones[index][1] == stones[i][1])){
                dfs(visited,stones,i);
            }
        }

    }

    int removeStones(vector<vector<int>>& stones) {
    //if two stones shares the same row or the same column, they are in same group and we want  just one stone to remove all other stone in a group .
     // hence question is count the connected component in a graph.
     // use dfs.
     //  Hence our answer will be total count - the number of the connected components

        int n = stones.size();
        vector<int> visited(n,0);
        int components =0;
        for(int i = 0; i < n; i++){

            if(!visited[i]){
                components++;
                dfs(visited, stones, i);
            }
        }

        return n-components;
    }
};