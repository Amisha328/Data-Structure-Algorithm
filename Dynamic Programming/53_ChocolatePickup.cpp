// Maximum number of chocolates Player can collect with the help of his friends
// Problem Statement: https://www.codingninjas.com/codestudio/problem-details/ninja-and-his-friends_3125885

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
          /*
          // Memoization: TC->O(r*c*c) * 9 | SC->O(r*c*c)+O(r)
          int solve(vector<vector<int>> &grid, int r, int c, int i, int j1, int j2, vector<vector<vector<int>>> &dp)
          {
                    if(j1 < 0 || j1 >= c || j2 < 0 || j2 >= c) return -1e8;
                    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
                    if(i == r-1) 
                    {
                              if(j1 == j2) return grid[i][j1];
                              else return grid[i][j1]+grid[i][j2];
                    }
                    
                    int ans = -1e8;
                    for(int dj1 = -1; dj1 <= +1; dj1++)
                    {
                              for(int dj2 = -1; dj2 <= +1; dj2++)
                              {
                                        if(j1 == j2)
                                        ans = max(ans, grid[i][j1] + solve(grid, r, c, i+1, dj1+j1, dj2+j2, dp));
                                        else
                                        ans = max(ans, grid[i][j1] + grid[i][j2] + solve(grid, r, c, i+1, dj1+j1, dj2+j2, dp));
                              }
                    }
          
                    return dp[i][j1][j2] = ans;
          }
          int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
                    // Write your code here.
                    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
                    return solve(grid, r, c, 0, 0, c-1, dp);
          }
          */

         /*
         //  Tabulation: TC->O(r*c*c) * 9 | SC->O(r*c*c)
         int maximumChocolates(int r, int c, vector<vector<int>> &grid) 
         {
          // Write your code here.
          vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
          for(int j1 = 0; j1 < c; j1++)
          {
                    for(int j2 = 0; j2 < c; j2++)
                    {
                              if(j1 == j2)
                              dp[r-1][j1][j2] = grid[r-1][j1];
                              else
                              dp[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2];
                    }
          }
          
          for(int i = r-2; i >= 0; i--)
          {
                    for(int j1 = 0; j1 < c; j1++)
                    {
                              for(int j2 = 0; j2 < c; j2++)
                              {
                                        int ans = -1e8;
                                        for(int dj1 = -1; dj1 <= +1; dj1++)
                                        {
                                                  for(int dj2 = -1; dj2 <= +1; dj2++)
                                                  {
                                                            int val = 0;
                                                            if(j1 == j2)
                                                                      val = grid[i][j1];
                                                            else
                                                            val = grid[i][j1] + grid[i][j2];
                                                            
                                                            if(j1+dj1 >= 0 && j1+dj1 < c && j2+dj2 >= 0 && j2+dj2 < c)
                                                                      val += dp[i+1][j1+dj1][j2+dj2];                                                        
                                                            else
                                                                      val = -1e8;
                                                            
                                                            ans = max(ans, val);
                                                  }
                                        }

                                        dp[i][j1][j2] = ans;
                              }
                    }
          }
          
           return dp[0][0][c-1];
          
          }
          */

         //  Space Optimization: TC->O(r*c*c) * 9 | SC->O(c*c)
         int maximumChocolates(int r, int c, vector<vector<int>> &grid) 
         {
          // Write your code here.
          vector<vector<int>> front(c, vector<int>(c, 0));
          vector<vector<int>> curr(c, vector<int>(c, 0));
          for(int j1 = 0; j1 < c; j1++)
          {
                    for(int j2 = 0; j2 < c; j2++)
                    {
                              if(j1 == j2)
                              front[j1][j2] = grid[r-1][j1];
                              else
                              front[j1][j2] = grid[r-1][j1] + grid[r-1][j2];
                    }
          }
          
          for(int i = r-2; i >= 0; i--)
          {
                    for(int j1 = 0; j1 < c; j1++)
                    {
                              for(int j2 = 0; j2 < c; j2++)
                              {
                                        int ans = -1e8;
                                        for(int dj1 = -1; dj1 <= +1; dj1++)
                                        {
                                                  for(int dj2 = -1; dj2 <= +1; dj2++)
                                                  {
                                                            int val = 0;
                                                            if(j1 == j2)
                                                                      val = grid[i][j1];
                                                            else
                                                                      val = grid[i][j1] + grid[i][j2];
                                                            
                                                            if(j1+dj1 >= 0 && j1+dj1 < c && j2+dj2 >= 0 && j2+dj2 < c)
                                                                      val += front[j1+dj1][j2+dj2];                                                       
                                                            else
                                                                      val = -1e8;
                                                            
                                                            ans = max(ans, val);
                                                  }
                                        }

                                        curr[j1][j2] = ans;
                              }
                              
                    }
                    front = curr;
          }
          
           return front[0][c-1];
          
          }
};

int main(){
        int r,c;
        cin>>r>>c;
        vector<vector<int>> Matrix(r, vector<int>(c, 0));
        for(int i = 0; i < r; i++)
        {
                  for(int j = 0; j < c; j++)
                  {
                            cin>>Matrix[i][j];
                  }
        }
        
        Solution ob;
        cout<<ob.maximumChocolates(r, c, Matrix)<<"\n";
    return 0;
}