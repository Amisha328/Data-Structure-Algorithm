// Unique Subset
// Problem link:
// https://leetcode.com/problems/subsets-ii/
// https://practice.geeksforgeeks.org/problems/subsets-1587115621/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<int> arr, int idx, vector<vector<int>> &ans, vector<int> &ds){
        ans.push_back(ds);
        for(int i = idx; i < arr.size(); i++){
            // if the next index number is same as the current index number 
            // for a particular subset length we will not take that.
            if(i > idx && arr[i] == arr[i-1]) continue;
            ds.push_back(arr[i]);
            solve(arr, i+1, ans, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<vector<int>> ans;
       vector<int> ds;
       sort(nums.begin(), nums.end());
       solve(nums, 0, ans, ds);
       return ans;
    }
};
