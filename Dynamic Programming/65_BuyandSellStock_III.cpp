// Best Time to Buy and Sell Stock III
// Problem link:
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
// https://www.codingninjas.com/codestudio/problems/buy-and-sell-stock-iii_1092612

#include <bits/stdc++.h>
using namespace std;

// Memoization:
// TC -> O(N X 2 X 3) | SC -> O(N X 2 X 3) + O(N)
class Solution {
private:
     int f(int idx, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>> &dp){
         if(cap == 0 || idx == prices.size()) return 0;
         if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];
         int profit = 0;
         if(buy){
             profit = max(-prices[idx] + f(idx+1, 0, cap, prices, dp),
                            0 + f(idx+1, 1, cap, prices, dp));
         }
         else {
             profit = max(prices[idx] + f(idx+1, 1, cap-1, prices, dp),
                            0 + f(idx+1, 0, cap, prices, dp));
         }
         return dp[idx][buy][cap] = profit;
     }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, 2, prices, dp);
    }
};

// Tabulation:
// TC -> O(N X 2 X 3) | SC -> O(N X 2 X 3)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        // Base case not required as 'dp' is already assigned as 0 initially
         for(int idx = n-1; idx >= 0; idx--){
           for(int buy = 0; buy <= 1; buy++){
               for(int cap = 1; cap <= 2; cap++){
                    int profit = 0;
                    if(buy){
                        profit = max(-prices[idx] + dp[idx+1][0][cap],
                                        0 + dp[idx+1][1][cap]);
                    }
                    else {
                        profit = max(prices[idx] + dp[idx+1][1][cap-1],
                                        0 + dp[idx+1][0][cap]);
                    }
                    dp[idx][buy][cap] = profit;
               }
           }
       }
       return dp[0][1][2];
    }
};

// Space Optimization
// TC -> O(N X 2 X 3) | SC -> O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ahead(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

       for(int idx = n-1; idx >= 0; idx--){
           for(int buy = 0; buy <= 1; buy++){
               for(int cap = 1; cap <= 2; cap++){
                    int profit = 0;
                    if(buy){
                        profit = max(-prices[idx] + ahead[0][cap],
                                        0 + ahead[1][cap]);
                    }
                    else {
                        profit = max(prices[idx] + ahead[1][cap-1],
                                        0 + ahead[0][cap]);
                    }
                    curr[buy][cap] = profit;
               }
               ahead = curr;
           }
       }
       return ahead[1][2];
    }
};


/***************** Another Approach ****************/

 /*
          B         S         B         S
          0         1         2         3
          even                even
 */


// Memoization:
// TC -> O(N X 4) | SC -> O(N X 4) + O(N)

class Solution {
private:
int f(int idx, int trans, vector<int>& prices, vector<vector<int>> &dp){
         if(idx == prices.size() || trans == 4) return 0;
         if(dp[idx][trans] != -1) return dp[idx][trans];
         int profit = 0;
         if(trans % 2 == 0){
              profit = max(-prices[idx] + f(idx+1, trans+1, prices, dp),
                            0 + f(idx+1, trans, prices, dp));
         }
         else{
             profit = max(prices[idx] + f(idx+1, trans+1, prices, dp),
                            0 + f(idx+1, trans, prices, dp));
         }
        return dp[idx][trans] = profit;
     }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(4, -1));
        return f(0, 0, prices, dp);
        }
};

// Tabulation:
// TC -> O(N X 4) | SC -> O(N X 4)

class Solution {
public:
int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(5, 0));
        for(int idx = n-1; idx >= 0; idx--){
           for(int trans = 3; trans >= 0; trans--){
               int profit = 0;
                if(trans % 2 == 0){
                    profit = max(-prices[idx] + dp[idx+1][trans+1],
                                    0 + dp[idx+1][trans]);
                }
                else{
                    profit = max(prices[idx] + dp[idx+1][trans+1],
                                    0 + dp[idx+1][trans]);
                }
                dp[idx][trans] = profit;
           }
       }
       return dp[0][0];
    }
};

// Space Optimization
// TC -> O(N X 4) | SC -> O(1)

class Solution {
public:
int maxProfit(vector<int>& prices) {
      int n = prices.size();
      vector<int> ahead(5, 0), curr(5, 0);
       for(int idx = n-1; idx >= 0; idx--){
           for(int trans = 3; trans >= 0; trans--){
               int profit = 0;
                if(trans % 2 == 0){
                    profit = max(-prices[idx] + ahead[trans+1],
                                    0 + ahead[trans]);
                }
                else{
                    profit = max(prices[idx] + ahead[trans+1],
                                    0 + ahead[trans]);
                }
                curr[trans] = profit;
           }
           ahead = curr;
       }
       return ahead[0];
    }
};