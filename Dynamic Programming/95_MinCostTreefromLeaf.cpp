// Minimum Cost Tree From Leaf Values
// Problem link:
// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/submissions/
// https://www.codingninjas.com/codestudio/problem-details/minimum-cost-tree-from-leaf-nodes_1266047

#include <bits/stdc++.h>
using namespace std;

// Memoization:

class Solution {
private:
    int solve(vector<int>& arr, map<pair<int, int>, int> &maxi, int left, int right,
    vector<vector<int>> &dp){
        // as we want the min sum of the values of each non-leaf node
        // leaf node
        if(left == right) return 0;
        if(dp[left][right] != -1) return dp[left][right];
        int ans = INT_MAX;
        for(int k = left; k < right; k++){
            ans = min(ans, maxi[{left, k}] * maxi[{k+1, right}] + 
                        solve(arr, maxi, left, k, dp) + solve(arr, maxi, k+1, right, dp));
        }
        return dp[left][right] = ans;
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        map<pair<int, int>, int> maxi;
        for(int i = 0; i < n; i++){
            maxi[{i, i}] = arr[i];
            for(int j = i+1; j < n; j++){
                maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }
        return solve(arr, maxi, 0, n-1, dp);
    }
};

// Tabulation

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        map<pair<int, int>, int> maxi;
        for(int i = 0; i < n; i++){
            maxi[{i, i}] = arr[i];
            for(int j = i+1; j < n; j++){
                maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }

        for(int left = n-1; left >= 0; left--){
            for(int right = left; right < n; right++){
                    if(left == right) continue;
                    int ans = INT_MAX;
                    for(int k = left; k < right; k++){
                        ans = min(ans, maxi[{left, k}] * maxi[{k+1, right}] + 
                                    dp[left][k] + dp[k+1][right]);
                    }
                    dp[left][right] = ans;
            }
        }
        return dp[0][n-1];
    }
};

// NOTE:
// This is not the optimal solution we can do this problem in O(n) byusing stacks