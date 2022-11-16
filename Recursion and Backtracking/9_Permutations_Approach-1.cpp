// Print all the permutations of a string/array
// Approach - 1
// Problem link:
// https://leetcode.com/problems/permutations/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Brute Force
    void solve(vector<int> &nums, vector<int> &freq, vector<vector<int>> &ans, vector<int> &ds){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i] = 1;
                solve(nums, freq, ans, ds);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> freq(nums.size(), 0);
        solve(nums, freq, ans, ds);
        return ans;
    }
};