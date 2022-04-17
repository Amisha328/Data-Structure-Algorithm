// Problem Statement: https://leetcode.com/problems/frog-jump/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[2001][2001];
    bool solve(vector<int> &stones, int lastIdx, int currIdx)
    {
        if(currIdx == stones.size()-1) return true;
        
        if(dp[lastIdx][currIdx]) return false; // as this combo of lastTdx and currIdx does not lead to last stone
        int lastJump = stones[currIdx] - stones[lastIdx];
        int nextIdx = currIdx + 1;
        
        while(nextIdx < stones.size() && stones[nextIdx] <= stones[currIdx] + lastJump + 1)
        {
            int nextJump = stones[nextIdx] - stones[currIdx];
            int jump = nextJump - lastJump;
            // if lastJump = k, then nextJump can be k-1, k and k+1
            // so range can be k-1-k = -1 to k+1-k = 1
            if(jump >= -1 && jump <= 1)
            {
                if(solve(stones, currIdx, nextIdx)) return true;
            }
            
            nextIdx++;
        }
        
        dp[lastIdx][currIdx] = true;
        
        return false;
        
    }
    bool canCross(vector<int>& stones) 
    {
        if(stones[1] - stones[0] != 1) return false;
        return solve(stones, 0, 1);
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
        cout << ob.canCross(v) << "\n";
	     
    return 0;
}

// Time complexity: O(n^2)
// Space complexity: O(n^2)