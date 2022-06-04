// Minimum Cost to Make at Least One Valid Path in a Grid
// Problme link: 
// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(int x, int y, int n, int m){
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        vector<pair<int, int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        dp[0][0] = 0;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int X = x + dir[i].first;
                int Y = y + dir[i].second;
                if(isValid(X, Y, n, m)){
                    // if the sign at (x,y) is same as what we need to go to (X,Y) so, sign need not be modified at (x,y)
                    if(i+1 == grid[x][y] && dp[X][Y] > dp[x][y])
                    {
                        dp[X][Y] = dp[x][y];
                        q.push({X,Y});
                    }
                    // if sign is differnt the we need to add the cost
                    else if(dp[x][y] + 1 < dp[X][Y]){
                        dp[X][Y] = dp[x][y] + 1;
                        q.push({X,Y});
                    }
                }
            }
        }
        return dp[n-1][m-1];
    }
};