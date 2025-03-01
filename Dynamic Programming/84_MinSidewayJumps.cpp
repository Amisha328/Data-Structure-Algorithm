// Minimum Sideway Jumps
// Problem link:
// https://leetcode.com/problems/minimum-sideway-jumps/description/

#include<bits/stdc++.h>
using namespace std;

// Memoization
// TC-> O(N X 3 X 3) ~ O(N) | SC -> O(4 X N) + O(N)
class Solution {
private:
    int solve(vector<int>& obstacles, int currlane, int currpos, vector<vector<int>> &dp){
        if(currpos == obstacles.size()-1) return 0;
        if(dp[currlane][currpos] != -1) return dp[currlane][currpos];
        if(obstacles[currpos+1] != currlane) 
            return dp[currlane][currpos] = solve(obstacles, currlane, currpos+1, dp);
        else{
            int ans = INT_MAX;
            for(int i = 1; i <= 3; i++){
                if(currlane != i && obstacles[currpos] != i)
                    ans = min(ans, 1 + solve(obstacles, i, currpos, dp));
            }
            return dp[currlane][currpos] = ans;
        }
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp(4, vector<int>(n, -1));
        return solve(obstacles, 2, 0, dp);
    }
};

// Tabulation
// TC-> O(N X 3 X 3) ~ (N) | SC -> O(4 X N) ~ O(N)
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp(4, vector<int>(n, 1e9));
        dp[0][n-1] = dp[1][n-1] = dp[2][n-1] = dp[3][n-1] = 0;

        for(int currpos = n-2; currpos >= 0; currpos--){
            for(int currlane = 1; currlane <= 3; currlane++){
                if(obstacles[currpos+1] != currlane) 
                    dp[currlane][currpos] = dp[currlane][currpos+1];
                else{
                     // sideways jump
                    int ans = 1e9;
                    for(int i = 1; i <= 3; i++){
                        if(currlane != i && obstacles[currpos] != i)
                            ans = min(ans, 1 + dp[i][currpos+1]);
                    }
                    dp[currlane][currpos] = ans;
                }
            }
        }
        return min(dp[2][0], min(1+dp[1][0], 1+dp[3][0]));
    }
};

// Space Optimization
// TC-> O(N X 3 X 3) ~ O(N) | SC -> O(8) ~ O(1)
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();

        vector<int> curr(4, 1e9), next(4, 1e9); // currpos array and currpos+1
        next[0] = next[1] = next[2] = next[3] = 0;
        for(int currpos = n-2; currpos >= 0; currpos--){
            for(int currlane = 1; currlane <= 3; currlane++){
                if(obstacles[currpos+1] != currlane) 
                    curr[currlane] = next[currlane];
                else{
                     // sideways jump
                    int ans = 1e9;
                    for(int i = 1; i <= 3; i++){
                        if(currlane != i && obstacles[currpos] != i)
                            ans = min(ans, 1 + next[i]);
                    }
                    curr[currlane] = ans;
                }
            }
            next = curr;
        }
        return min(next[2], min(1+next[1], 1+next[3]));
    }
};