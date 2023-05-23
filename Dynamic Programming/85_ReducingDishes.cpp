// Reducing Dishes
// Problem link:
// https://leetcode.com/problems/reducing-dishes/description/

#include<bits/stdc++.h>
using namespace std;

// Memoization
// TC -> O(N X N) | SC -> O(N X N) + O(N)
class Solution {
private:
    int solve(vector<int>& satisfaction, int index, int time, vector<vector<int>> &dp){
        if(index == satisfaction.size()) return 0;
        if(dp[index][time] != -1) return dp[index][time];
        int include = satisfaction[index] * time + solve(satisfaction, index+1, time+1, dp);
        int exclude = 0 + solve(satisfaction, index+1, time, dp);

        return dp[index][time] = max(include, exclude);
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(satisfaction.size()+1, vector<int> (satisfaction.size()+1, -1));
        return solve(satisfaction, 0, 1, dp);
    }
};

// Tabulation
// TC -> O(N X N) | SC -> O(N X N)
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<vector<int>> dp(n+2, vector<int> (n+2, 0));
        for(int index = n-1; index >= 0; index--){
            for(int time = n; time >= 1; time--){
                int include = satisfaction[index] * time + dp[index+1][time+1];
                int exclude = 0 + dp[index+1][time];

                dp[index][time] = max(include, exclude);
            }
        }
        return dp[0][1];
    }
};

// Space Optimization:
// TC -> O(N X N) | SC -> O(N)
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<int> curr(n+2, 0), next(n+2, 0);
        for(int index = n-1; index >= 0; index--){
            for(int time = n; time >= 1; time--){
                int include = satisfaction[index] * time + next[time+1];
                int exclude = 0 + next[time];

                curr[time] = max(include, exclude);
            }
            next = curr;
        }
        return next[1];
    }
};