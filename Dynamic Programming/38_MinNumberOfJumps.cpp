// Minimum number of jumps to reach end
// Problem link: https://leetcode.com/problems/jump-game-ii/
// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1#

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        dp[0] = 0;
        for(int i = 1; i < n; i++)
                dp[i] = INT_MAX;

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(j+nums[j] >= i && nums[j] != 0)
                {
                    if(dp[j] != INT_MAX)
                        dp[i] = min(dp[i], dp[j]+1);
                }
            }
        }
        
        return dp[n-1];
    }
};

int main() 
{
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i = 0; i < n; i++)
          cin>>v[i];

      
        Solution ob;
        cout << ob.jump(v) << "\n";
	     
    return 0;
}

// Time complexity: O(n^2)
// Space complexity: O(n)