// Unique Permuations
// Two Approaches
// Problem link:
// https://leetcode.com/problems/permutations-ii/submissions/

#include<bits/stdc++.h>
using namespace std;

// Brute Force - Recusion and Backtracking
class Solution {
public:
     // Brute Force
      void solve(vector<int> &nums, vector<int> &freq, vector<vector<int>> &ans, vector<int> &ds){
        if(ds.size() == nums.size()){
            if(find(ans.begin(), ans.end(), ds) == ans.end()){
                ans.push_back(ds);
                return;
            }
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
   vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> freq(nums.size(), 0);
        solve(nums, freq, ans, ds);
        return ans;
    }
};

// Better Solution
void solve(vector<int> &nums, int index, set<vector<int>> &temp){
        if(index == nums.size()){
            temp.insert(nums);
            return;
        }
        for(int i = index; i < nums.size(); i++){
            if(i > index && nums[i] == nums[i-1]) continue;
            swap(nums[i], nums[index]);
            solve(nums, index+1, temp);
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> temp;
        solve(nums, 0, temp);
        for(auto it: temp){
            ans.push_back(it);
        }
        return ans;
}

// Optimal Solution
void solve(vector<int> nums, int index, vector<vector<int>> &ans){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = index; i < nums.size(); i++){
            // this condition won't eliminate duplicate completely. 
            // This condition only preventing putting same number in the front given that all same number stay together. 
            // However, by swapping, the originally contiguous equal numbers will break.
            // Hence swapping back is not used.
            if(i != index && nums[i] == nums[index]) continue;
            swap(nums[i], nums[index]);
            solve(nums, index+1, ans);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        solve(nums, 0, ans);
        return ans;
    }
