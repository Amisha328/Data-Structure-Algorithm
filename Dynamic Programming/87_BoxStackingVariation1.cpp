// Maximum Height by Stacking Cuboids
// Problem link:
// https://leetcode.com/problems/maximum-height-by-stacking-cuboids/description/

#include <bits/stdc++.h>
using namespace std;

// Memoization
// TC-> O(NlogN) + O(N^2) | SC-> O(N^2) | O(N)
class Solution {
private:
    bool check(vector<int> &baseBox, vector<int> &newBox){
        if(newBox[0] <= baseBox[0] && newBox[1] <= baseBox[1] && newBox[2] <= baseBox[2])
                return true;
        return false;
    }
    // LIS - Memoization code
    int solve(vector<vector<int>>& cuboids, int curr, int prev, vector<vector<int>> &dp){
        if(curr == cuboids.size()) return 0;
        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];

        // include
        int take = 0;
        if(prev == -1 || check(cuboids[curr], cuboids[prev]))
            take = cuboids[curr][2] + solve(cuboids, curr+1, curr, dp);
        
        // exclude
        int notTake = 0 + solve(cuboids, curr+1, prev, dp);

        return dp[curr][prev+1] = max(take, notTake);
    }
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        // Step 1: sort among the dimensions for every cuboids
        for(auto &c: cuboids){
            sort(c.begin(), c.end());
        }

        // Step2: sort all the cuboids wrt width
        sort(cuboids.begin(), cuboids.end());

        // Step3: Now apply LIS
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(cuboids, 0, -1, dp);
    }
};


// Tabulation
// TC-> O(NlogN) + O(N^2) | SC-> O(N^2) 
class Solution {
private:
    bool check(vector<int> &baseBox, vector<int> &newBox){
        if(newBox[0] <= baseBox[0] && newBox[1] <= baseBox[1] && newBox[2] <= baseBox[2])
                return true;
        return false;
    }
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        // Step 1: sort among the dimensions for every cuboids
        for(auto &c: cuboids){
            sort(c.begin(), c.end());
        }

        // Step2: sort all the cuboids wrt width
        sort(cuboids.begin(), cuboids.end());

        // Tabulation
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int curr = n-1; curr >= 0; curr--){
            for(int prev = curr-1; prev >= -1; prev--){
                // include
                int take = 0;
                if(prev == -1 || check(cuboids[curr], cuboids[prev]))
                    take = cuboids[curr][2] + dp[curr+1][curr+1];
                
                // exclude
                int notTake = 0 + dp[curr+1][prev+1];

                dp[curr][prev+1] = max(take, notTake);
            }
        }
        return dp[0][-1+1];
    }
};

// Space Optimization
// TC-> O(NlogN) + O(N^2) | SC-> O(N) 
class Solution {
private:
    bool check(vector<int> &baseBox, vector<int> &newBox){
        if(newBox[0] <= baseBox[0] && newBox[1] <= baseBox[1] && newBox[2] <= baseBox[2])
                return true;
        return false;
    }

    int solve(vector<vector<int>>& cuboids, int curr, int prev, vector<vector<int>> &dp){
        if(curr == cuboids.size()) return 0;
        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];

        // include
        int take = 0;
        if(prev == -1 || check(cuboids[curr], cuboids[prev]))
            take = cuboids[curr][2] + solve(cuboids, curr+1, curr, dp);
        
        // exclude
        int notTake = 0 + solve(cuboids, curr+1, prev, dp);

        return dp[curr][prev+1] = max(take, notTake);
    }
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        // Step 1: sort among the dimensions for every cuboids
        for(auto &c: cuboids){
            sort(c.begin(), c.end());
        }

        // Step2: sort all the cuboids wrt width
        sort(cuboids.begin(), cuboids.end());

        // Step3: Now apply LIS
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);
        
        for(int curr = n-1; curr>=0; curr--){
            for(int prev = curr-1; prev>=-1; prev--){
                
                // include
                int take = 0;
                if(prev == -1 || check(cuboids[curr], cuboids[prev]))
                    take = cuboids[curr][2] + nextRow[curr+1];
                    
                // exclude
                int notTake = 0 + nextRow[prev+1];
                
                currRow[prev+1] = max(take, notTake);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }
};