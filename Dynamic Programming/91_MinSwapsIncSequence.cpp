// Minimum Swaps To Make Sequences Increasing
// Problem link:
// https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/

#include <bits/stdc++.h>
using namespace std;


// Memoization Code:
// TC -> O(N X 2) | SC -> O(N X 2) ~ O(N) + stack space
class Solution {
private:
    int solve(vector<int>& nums1, vector<int>& nums2, int index, int swapped, vector<vector<int>> &dp){
        if(index == nums1.size()) return 0;
        // get the previous elements to check for strictly increaing sequence
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        if(dp[index][swapped] != -1) return dp[index][swapped];
        
        // if prev index values where swaped
        if(swapped)
            swap(prev1, prev2);
        
        int ans = INT_MAX;
        // no-swap for curr index
        if(nums1[index] > prev1 && nums2[index] > prev2)
            ans = solve(nums1, nums2, index+1, 0, dp);
        
        // swap for curr-index is required
        // we have to check if the sequnece will become strictly increaing after swapping
        // hence we check curr index values for nums1 with prev2 and for nums2 with prev1
        // if it becomes strictly increasing then we set swapped flag as 1
        // indicating we have swapped the current index values.
        if(nums1[index] > prev2 && nums2[index] > prev1)
            ans = min(ans, 1 + solve(nums1, nums2, index+1, 1, dp));

        return dp[index][swapped] = ans;
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        //vector<int> dp(nums1.size(), -1);
        vector<vector<int>> dp(nums1.size(), vector<int>(2, -1));
        return solve(nums1, nums2, 1, 0, dp);
    }
};

// Tabulation
// TC -> O(N X 2) | SC -> O(N X 2) ~ O(N)
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        int n = nums1.size();

       vector<vector<int>> dp(n+1, vector<int>(2, 0));
       for(int index = n-1; index >= 1; index--){
           for(int swapped = 1; swapped >= 0; swapped--){
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                // if prev index values where swaped
                if(swapped)
                    swap(prev1, prev2);
                
                int ans = INT_MAX;
                // no-swap for curr index
                if(nums1[index] > prev1 && nums2[index] > prev2)
                    ans = dp[index+1][0];
                
                // swap for curr-index is required
                // we have to check if the sequnece will become strictly increaing after swapping
                // hence we check curr index values for nums1 with prev2 and for nums2 with prev1
                // if it becomes strictly increasing then we set swapped flag as 1
                // indicating we have swapped the current index values.
                if(nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans, 1 + dp[index+1][1]);

                dp[index][swapped] = ans;
           }
       }
       return dp[1][0];
    }
};

// Space Optimization
// TC -> O(N X 2) | SC -> O(4) ~ O(1)
class Solution {
public:
   int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        int n = nums1.size();

       vector<int> curr(2, 0), next(2, 0);
       for(int index = n-1; index >= 1; index--){
           for(int swapped = 1; swapped >= 0; swapped--){
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                // if prev index values where swaped
                if(swapped)
                    swap(prev1, prev2);
                
                int ans = INT_MAX;
                // no-swap for curr index
                if(nums1[index] > prev1 && nums2[index] > prev2)
                    ans = next[0];
                
                // swap for curr-index is required
                // we have to check if the sequnece will become strictly increaing after swapping
                // hence we check curr index values for nums1 with prev2 and for nums2 with prev1
                // if it becomes strictly increasing then we set swapped flag as 1
                // indicating we have swapped the current index values.
                if(nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans, 1 + next[1]);

                curr[swapped] = ans;
           }
           next = curr;
       }
       return next[0];
    }
};

// Space Optimization using variables
// TC -> O(N X 2) | SC -> O(1)
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        int n = nums1.size();

       int currSwap = 0, currNoSwap = 0, nextSwap = 0, nextNoSwap= 0;
       for(int index = n-1; index >= 1; index--){
           for(int swapped = 1; swapped >= 0; swapped--){
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                // if prev index values where swaped
                if(swapped)
                    swap(prev1, prev2);
                
                int ans = INT_MAX;
                // no-swap for curr index
                if(nums1[index] > prev1 && nums2[index] > prev2)
                    ans = nextNoSwap;
                
                // swap for curr-index is required
                // we have to check if the sequnece will become strictly increaing after swapping
                // hence we check curr index values for nums1 with prev2 and for nums2 with prev1
                // if it becomes strictly increasing then we set swapped flag as 1
                // indicating we have swapped the current index values.
                if(nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans, 1 + nextSwap);

                if(swapped) currSwap = ans;
                else currNoSwap = ans;
           }
           nextSwap = currSwap;
           nextNoSwap = currNoSwap;
       }
       return min(nextSwap, nextNoSwap);
    }
};