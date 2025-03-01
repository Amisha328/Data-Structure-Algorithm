// Number of Dice Rolls With Target Sum
// Problem link:
// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/
// https://practice.geeksforgeeks.org/problems/dice-throw5349/1?
// https://www.codingninjas.com/codestudio/problem-details/dice-throws_799924

#include<bits/stdc++.h> 
using namespace std; 


// Memoization
// TC-> O(no. of dices X target X faces) | SC-> O(no. of dices X target) + Stack space
class Solution {
  private:
    long long solve(int dices, int faces, int target, vector<vector<long long>> &dp){
        if(target < 0) return 0;
        // no dices is left but the target is not 0 yet
        if(dices == 0 && target != 0) return 0;
        // if target is zero and still some dices are there
        if(dices != 0 && target == 0) return 0;
        // if dices and target both are zero then we do nothing hence 1 possibility
        if(dices == 0 && target == 0) return 1;
        if(dp[dices][target] != -1) return dp[dices][target];
        long long ans = 0;
        for(int i = 1; i <= faces; i++)
            ans += solve(dices-1, faces, target-i, dp);
        return dp[dices][target] = ans;
    }
  public:
    long long noOfWays(int M , int N , int X) {
        vector<vector<long long>> dp(N+1, vector<long long> (X+1, -1));
        return solve(N, M, X, dp);
    }
};

// Tabulation
// TC-> O(no. of dices X target X faces) | SC-> O(no. of dices X target)
class Solution {
  public:
    long long noOfWays(int M , int N , int X) {
        vector<vector<long long>> dp(N+1, vector<long long> (X+1, 0));
        dp[0][0] = 1;
        for(int dices = 1; dices <= N; dices++){
            for(int target = 1; target <= X; target++){
                long long ans = 0;
                for(int i = 1; i <= M; i++)
                    if(target-i >= 0)
                        ans += dp[dices-1][target-i];
                dp[dices][target] = ans;
            }
        }
        return dp[N][X];
    }
};

// Space Optimization
// TC-> O(no. of dices X target X faces) | SC-> O(target)
class Solution {
  public:
    long long noOfWays(int M , int N , int X) {
        vector<long long> curr(X+1, 0), prev(X+1, 0);
        prev[0] = 1;
        for(int dices = 1; dices <= N; dices++){
            for(int target = 1; target <= X; target++){
                long long ans = 0;
                for(int i = 1; i <= M; i++)
                    if(target-i >= 0)
                        ans += prev[target-i];
                curr[target] = ans;
            }
            prev = curr;
        }
        return prev[X];
    }
};