// Combination Sum
// Problem link: 
// https://leetcode.com/problems/combination-sum/
// https://www.codingninjas.com/codestudio/problem-details/combination-sum_981296
// TC-> O(2^t) * K

#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int idx, int target, vector<vector<int>> &ans, vector<int> &ds)     {
        if(idx == arr.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        
        // pick condition
        if(arr[idx] <= target){
            ds.push_back(arr[idx]);
            // idx+1 is not used as same number can be used unlimited number of times
            solve(arr, idx, target-arr[idx], ans, ds);
            ds.pop_back();
        }
        // not pick condition
        solve(arr, idx+1, target, ans, ds);
}
vector<vector<int>> combinationSum(vector<int>& arr, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        
        solve(arr, 0, n, ans, ds);
        
        return ans;
}

