// Ninja’s Training
// Problem Statement: https://www.codingninjas.com/codestudio/problem-details/ninja-s-training_3621003

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
// Memoization : TC->O(n*4)*3[loop runs 3 times]  SC->O(n)[stack space] + O(n*4)[matrix]
int solve(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    int maxi;
    if(day == 0)
    {
        maxi = 0;
        for(int task = 0; task <= 2; task++)
        {
            if(task != last)
                maxi = max(maxi,points[day][task]);
        }
        return maxi;
    }
    if(dp[day][last] != -1) return dp[day][last];
    maxi = 0;
    for(int task = 0; task <= 2; task++)
    {
         if(task != last)
         {
              int temp = points[day][task] + solve(day-1, task, points, dp);
              maxi = max(maxi, temp);
         }
     }
     return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, -1));
    // return solve(n-1, 3, points, dp); 
    /*
    // Tabulation:  TC->O(n*4)*3[loop runs 3 times]  SC->O(n*4)[matrix]
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
    
    for(int day = 1; day < n; day++)
    {
        for(int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            for(int task = 0; task < 3; task++)
            {
                if(task != last)
                {
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
                
            }
        }
    }
    return dp[n-1][3];
    */

   // Space Optimization: TC->O(n*4)*3 | SC->O(4)
    vector<int> prev(4, 0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));
    
    for(int day = 1; day < n; day++)
    {
        vector<int> temp(4,0);
        for(int last = 0; last < 4; last++)
        {
            temp[last] = 0;
            for(int task = 0; task < 3; task++)
            {
                if(task != last)
                {
                    int point = points[day][task] + prev[task];
                    temp[last] = max(temp[last], point);
                } 
            }
        }
        prev = temp;
    }
    return prev[3];
}
};
int main() {
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(3));
        for (int i = 0; i < n; i++) 
          for(int j = 0; j < 3; j++)
                    cin>>arr[i][j];
        Solution ob;
        cout << ob.ninjaTraining(n,arr)<< endl;
    return 0;
} 