// Longest Increasing Subsequence
// Problem Statement: https://leetcode.com/problems/longest-increasing-subsequence/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
/*
// Binary Search Approach - 
// time complexity: O(nlogn)
// space complexity: O(n)

    // Binary seach to find the index of ceiling value in tail array
    int ceilIndex(int tail[], int l, int h, int val)
    {
        while(l < h)
        {
            int m = (l+h)/2;
            if(tail[m] >= val)
                h = m;
            else
                l = m+1;
        }
        return h;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int tail[n];
        int len = 1;
        tail[0] = nums[0];
        
        for(int i = 1; i < n; i++)
        {
            // insert in tail array if higher number is found
            if(tail[len-1] < nums[i])
                tail[len++] = nums[i];
            else
            {
                // replace the current number with the ceiling value in sorted array tail
                // the ceiling of x is the smallest element in array greater than or equal to x
                int c = ceilIndex(tail, 0, len-1, nums[i]);
                tail[c] = nums[i];
            }
        }
        
        return len;
    }
    */

          // Dynamic Programming Approach - 
          // Time complexity: O(n^2)
          // Space complexity: O(n)
          int lengthOfLIS(vector<int>& nums) {
                    int n = nums.size();
                    int lis[n];
                    lis[0] = 1;
                    for(int i = 1; i < n; i++)
                    {
                              lis[i] = 1;
                              for(int j = 0; j < i; j++)
                              {
                                        if(nums[j] < nums[i])
                                                  lis[i] = max(lis[i], lis[j]+1);
                              }
                    }
                    return *max_element(lis, lis+n);
          }


};

int main()
{
          Solution s;
          int n;
          cin>>n;
          vector<int> nums;
          for(int i = 0; i < n; i++)
          {
              int x;
              cin>>x;
              nums.push_back(x);
          }
          cout << s.lengthOfLIS(nums) << endl;
          return 0;
}


