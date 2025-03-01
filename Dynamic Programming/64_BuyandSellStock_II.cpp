// Buy and Sell Stock - II
// Problem links:
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
// https://www.codingninjas.com/codestudio/problem-details/selling-stock_630282

#include <bits/stdc++.h>
using namespace std;

// Memoization:
// TC -> O(N X 2) | SC -> O(N X 2) + O(N)
class Solution {
private:
    int f(int idx, int buy, vector<int>& prices, vector<vector<int>> &dp){
        if(idx == prices.size()) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        int profit = 0;
        if(buy){
            profit = max(-prices[idx] + f(idx+1, 0, prices, dp), 
                                0 + f(idx+1, 1, prices, dp));
        }
        else{
             profit = max(prices[idx] + f(idx+1, 1, prices, dp), 
                            0 + f(idx+1, 0, prices, dp));
        }
        return dp[idx][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, prices, dp);
    }
};

// Tabulation:
// TC -> O(N X 2) | SC -> O(N X 2)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        dp[n][0] = dp[n][1] = 0;

        for(int idx = n-1; idx >= 0; idx--){
            for(int buy = 0; buy <= 1; buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[idx] + dp[idx+1][0], 
                                        0 + dp[idx+1][1]);
                }
                else{
                    profit = max(prices[idx] + dp[idx+1][1], 
                                    0 + dp[idx+1][0]);
                }
                dp[idx][buy] = profit;
            }
        }
        return dp[0][1];
    }
};

// Space Optimization
// TC -> O(N X 2) | SC -> O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> ahead(2, 0), curr(2, 0);
        ahead[0] = ahead[1] = 0;

        for(int idx = n-1; idx >= 0; idx--){
            for(int buy = 0; buy <= 1; buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[idx] + ahead[0], 
                                        0 + ahead[1]);
                }
                else{
                    profit = max(prices[idx] + ahead[1], 
                                    0 + ahead[0]);
                }
                curr[buy] = profit;
            }
            ahead = curr;
        }
        return ahead[1];
    }
};

// Using variable for space optimization
// TC -> O(N X 2) | SC -> O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int aheadNotBuy, aheadBuy, currNotBuy, currBuy;

        aheadNotBuy = aheadBuy = 0;

        for(int idx = n-1; idx >= 0; idx--){

                    currBuy = max(-prices[idx] + aheadNotBuy, 
                                        0 + aheadBuy);
                    currNotBuy = max(prices[idx] + aheadBuy, 
                                    0 + aheadNotBuy);
                    aheadNotBuy = currNotBuy;
                    aheadBuy = currBuy;
        }
        return aheadBuy;
    }
};


