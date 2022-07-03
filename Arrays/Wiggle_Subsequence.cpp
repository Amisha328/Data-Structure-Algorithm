// Wiggle Subsequence or Longest Zig-Zag Sub Sequence
// Problem link: 
// https://leetcode.com/problems/wiggle-subsequence/
// https://practice.geeksforgeeks.org/problems/longest-zig-zag-sub-sequence2656/1/#

#include<bits/stdc++.h>
using namespace std;

// TC-> O(n) | SC-> O(1)
class Solution {
	public:
    	// Idea:
          // All the consecutive ups are getting normalized by the same number of downs and vice-versa.
	int ZigZagMaxLength(vector<int>& nums)
          {
	  if(nums.size() <= 1) return nums.size();
            int up = 1, down = 1;
            for(int i = 0; i < nums.size()-1; i++){
                if(nums[i] < nums[i+1]) // up case
                    up = down + 1;
                else if(nums[i] > nums[i+1]) // down case
                    down = up + 1;
            }
            return max(up, down);
	}

};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.ZigZagMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}
