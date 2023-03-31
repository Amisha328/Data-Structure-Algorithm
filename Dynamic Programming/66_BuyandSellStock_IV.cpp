// Best Time to Buy and Sell Stock IV
// Problem link:
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
// https://practice.geeksforgeeks.org/problems/maximum-profit4657/1?
// https://www.codingninjas.com/codestudio/problems/best-time-to-buy-and-sell-stock_1080698

#include <bits/stdc++.h>
using namespace std;

// Memoization:
// TC -> O(N X K X 2) | SC -> O(N X K X 2) + O(N)

class Solution {
    private:
     int f(int idx, int trans, vector<int>& prices, vector<vector<int>> &dp, int k){
             if(idx == prices.size() || trans == k*2) return 0;
             if(dp[idx][trans] != -1) return dp[idx][trans];
             int profit = 0;
             if(trans % 2 == 0){
                  profit = max(-prices[idx] + f(idx+1, trans+1, prices, dp, k),
                                0 + f(idx+1, trans, prices, dp, k));
             }
             else{
                 profit = max(prices[idx] + f(idx+1, trans+1, prices, dp, k),
                                0 + f(idx+1, trans, prices, dp, k));
             }
            return dp[idx][trans] = profit;
         }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(k*2, -1));
        return f(0, 0, prices, dp, k);
    }
};

// Tabulation:
// TC -> O(N X K X 2) | SC -> O(N X K X 2)

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(k*2+1, 0));
        // return f(0, 0, prices, dp, k);

        for(int idx = n-1; idx >= 0; idx--){
            for(int trans = (k*2)-1; trans >= 0; trans--){
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
// TC -> O(N X K X 2) | SC -> O(1)

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(); 
        vector<int> ahead((k*2)+1, 0), curr((k*2)+1, 0);
        for(int idx = n-1; idx >= 0; idx--){
           for(int trans = (k*2)-1; trans >= 0; trans--){
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