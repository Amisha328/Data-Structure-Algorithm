// House Robber II - Same as Maximum sum such that no two elements are adjacent
// Problem link: https://leetcode.com/problems/house-robber-ii/
// https://www.codingninjas.com/codestudio/problems/house-robber_839733

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int> &arr)
    {
        int n = arr.size();
        if(n == 1) return arr[0];
	    
	    int prev_prev = arr[0];
	    int prev = max(arr[0], arr[1]);
	    
	    int res = prev;
	    for(int i = 3; i <= n; i++)
	    {
	        res = max(prev, prev_prev+arr[i-1]);
	        prev_prev = prev;
	        prev = res;
	    }
	    
	    return res;
    }
    
    int rob(vector<int>& nums) 
    {
        vector<int> temp1, temp2;
        if(nums.size() == 1) return nums[0];
        for(int i = 0; i < nums.size(); i++)
        {
            if(i != 0) temp1.push_back(nums[i]);
            if(i != nums.size()-1) temp2.push_back(nums[i]);
        }
        return max(solve(temp1), solve(temp2));
    }
};

int main() {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.rob(arr) << endl;
    return 0;
} 

// Time Complexity: O(n)
// Auxiliary Space: O(1)