// Minimum Cost For Tickets
// Problem link:
// https://leetcode.com/problems/minimum-cost-for-tickets/description/
// https://www.codingninjas.com/codestudio/problems/minimum-coins_2180776?leftPanelTab=1

#include<bits/stdc++.h>
using namespace std;

// Memoization:
// TC-> O(N) [N ranges from t to 365] ~ O(1) | SC -> O(N) + ON
class Solution {
private:
    int f(int n, vector<int>& days, vector<int>& costs, int index, vector<int> &dp){
        if(index >= n) return 0;
        if(dp[index] != -1) return dp[index];
        // 1 day pass
        int option1 = costs[0] + f(n, days, costs, index+1, dp);

        int i;
        // 7-days pass
        for(i = index; i < n && days[i] < days[index]+7; i++);
        int option2 = costs[1] + f(n, days, costs, i, dp);

        // 30-days pass
        for(i = index; i < n && days[i] < days[index]+30; i++);
        int option3 = costs[2] + f(n, days, costs, i, dp);

        return dp[index] = min(option1, min(option2, option3));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, -1);
        return f(n, days, costs, 0, dp);
    }
};

// Tabulation
// TC-> O(N) [N ranges from t to 365] ~ O(1) | SC -> O(N)
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, INT_MAX);
        dp[n] = 0;
        for(int index = n-1; index >= 0; index--){
            // 1 day pass
            int option1 = costs[0] + dp[index+1];

            int i;
            // 7-days pass
            for(i = index; i < n && days[i] < days[index]+7; i++);
            int option2 = costs[1] + dp[i];

            // 30-days pass
            for(i = index; i < n && days[i] < days[index]+30; i++);
            int option3 = costs[2] + dp[i];

            dp[index] = min(option1, min(option2, option3));
        }
        return dp[0];
    }
};

// Space Optimization
// TC-> O(N) [N ranges from t to 365] ~ O(1) | SC -> O(1)

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int ans = 0;
        queue<pair<int, int>> monthly;
        queue<pair<int, int>> weekly;
        for(auto day: days){
            // step1: remove the expired days
            while(!monthly.empty()  && monthly.front().first + 30 <= day)
                monthly.pop();
            
            while(!weekly.empty() && weekly.front().first + 7 <= day)
                weekly.pop();

            // step2: push the current day cost
            monthly.push({day, costs[2]+ans});
            weekly.push({day, costs[1]+ans});

            // step3: answer update
            ans = min(ans+costs[0], min(weekly.front().second, monthly.front().second));
        }
        return ans;
    }
};