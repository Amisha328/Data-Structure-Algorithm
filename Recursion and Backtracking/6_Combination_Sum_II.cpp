// Combinational Sum - II
// Problem link:
// https://leetcode.com/problems/combination-sum-ii/
// https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void combine(vector<vector<int>> &ans, vector<int> &arr, vector<int> &sol, int target, int idx)
    {
        if(target == 0)
        {
            ans.push_back(sol);
            return;
        }
        for(int i = idx; i < arr.size(); i++)
        {
            if(arr[i] > target) break;
            
            // i = 2 and idx = 1 arr[2] == arr[1] = 1
            // not the create the combination of duplicate elements again
            if(i > idx && arr[i] == arr[i-1])  
                continue;
            
            sol.push_back(arr[i]);
            combine(ans,arr,sol,target-arr[i],i+1);
            sol.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> sol;
        
        sort(arr.begin(),arr.end());
        
        combine(ans,arr,sol,target,0);
        
        return ans;
    }
};
