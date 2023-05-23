// Pizza With 3n Slices
// Problem link:
// https://leetcode.com/problems/pizza-with-3n-slices/description/
// https://www.codingninjas.com/codestudio/problem-details/pizza-sharing_3161885

#include <bits/stdc++.h>
using namespace std;

// Memoization
class Solution {
private:
    int solve(int index, int lastIndex, vector<int>& slices, int n, vector<vector<int>> &dp){
        if(n == 0 || index > lastIndex) return 0;
        if(dp[index][n] != -1) return dp[index][n];
        int take = slices[index] + solve(index+2, lastIndex, slices, n-1, dp);
        int notTake = 0 + solve(index+1, lastIndex, slices, n, dp);
        return dp[index][n] = max(take, notTake);
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        // total slices = 3n 
        // there are three people
        // Number of slices that I will eat => 3n/3 = n
        int k = slices.size(); // 3n
        vector<vector<int>> dp1(k, vector<int>(k, -1));
        // we are taking the first slice hence, excluding the last slice
        int case1 = solve(0, k-2, slices, k/3, dp1);
        // we are taking the last slice hence, excluding the first slice
        vector<vector<int>> dp2(k, vector<int>(k, -1));
        int case2 = solve(1, k-1, slices, k/3, dp2);

        return max(case1, case2);
    }
};

// Tabulation

class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        // total slices = 3n 
        // there are three people
        // Number of slices that I will eat => 3n/3 = n
        int k = slices.size(); // 3n

        vector<vector<int>> dp1(k+2,vector<int> (k+2, 0));
        vector<vector<int>> dp2(k+2,vector<int> (k+2, 0));

        // Case 1
        for(int index = k-2; index >= 0; index--){
            for(int n = 1; n <= k/3; n++){
                int take = slices[index] + dp1[index+2][n-1];
                int notTake = 0 + dp1[index+1][n];
                dp1[index][n] = max(take, notTake);
            }
        }

        // Case 2
        for(int index = k-1; index >= 1; index--){
            for(int n = 1; n <= k/3; n++){
                int take = slices[index] + dp2[index+2][n-1];
                int notTake = 0 + dp2[index+1][n];
                dp2[index][n] = max(take, notTake);
            }
        }
        return max(dp1[0][k/3], dp2[1][k/3]);
    }
};

// Space Optimization

class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        // total slices = 3n 
        // there are three people
        // Number of slices that I will eat => 3n/3 = n
        int k = slices.size(); // 3n

        vector<int> curr1(k, 0), next1(k, 0), next_next1(k, 0);
        vector<int> curr2(k, 0), next2(k, 0), next_next2(k, 0);

        // Case 1
        for(int index = k-2; index >= 0; index--){
            for(int n = 1; n <= k/3; n++){
                int take = slices[index] + next_next1[n-1];
                int notTake = 0 + next1[n];
                curr1[n] = max(take, notTake);
            }
            next_next1 = next1;
            next1 = curr1;
        }

        // Case 2
        for(int index = k-1; index >= 1; index--){
            for(int n = 1; n <= k/3; n++){
                int take = slices[index] + next_next2[n-1];
                int notTake = 0 + next2[n];
                curr2[n] = max(take, notTake);
            }
            next_next2 = next2;
            next2 = curr2;
        }
        return max(next1[k/3], next2[k/3]);
    }
};