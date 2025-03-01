// Minimum Cost to Cut a Stick
// Problem link:
// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/
// https://www.codingninjas.com/codestudio/problem-details/cost-to-cut-a-chocolate_3208460

#include <bits/stdc++.h> 
using namespace std;

// Memoization
// TC -> O(N X N X N) | SC -> O(N X N) + O(N)
class Solution {
private:
    int f(int i, int j, vector<int>& cuts, vector<vector<int>> &dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for(int idx = i; idx <= j; idx++){
            int cost = cuts[j+1]-cuts[i-1] + f(i, idx-1, cuts, dp) + f(idx+1, j, cuts, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c+1, vector<int>(c+1, -1));
        return f(1, c, cuts, dp);
    }
};

// Tabulation:
// TC -> O(N X N X N) | SC -> O(N X N)

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c+2, vector<int>(c+2, 0));
        // return f(1, c, cuts, dp);
        for(int i = c; i >= 1; i--){
            for(int j = 1; j <= c; j++){
                if(i > j) continue;
                int mini = INT_MAX;
                for(int idx = i; idx <= j; idx++){
                    int cost = cuts[j+1]-cuts[i-1] + dp[i][idx-1] + dp[idx+1][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c];
    }
};