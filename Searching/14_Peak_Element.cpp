/*
Given an array of integers, find a peak element in it. An array element is peak if it is NOT smaller than its neighbors. 
For corner elements, we need to consider only one neighbor. 

// Problem link:
https://www.codingninjas.com/studio/problems/find-peak-element_1081482?
https://leetcode.com/problems/find-peak-element/
*/

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int predicate(vector<int> &nums, int mid){
        if(nums[mid] < nums[mid+1]) return 0;
        else return 1;
}
int findPeakElement(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;

        int L = -1, R = nums.size();
        while(L + 1 < R){
            int M = L + (R - L)/2;
            if(predicate(nums, M) == 0) L = M;
            else R = M;
        }
        return R;
       
        /*

        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;
        
        int low = 0, high = n-1;
        
        while(low <= high)
        {
            int mid = low + (high -low)/2;
            // If arr[mid] is the peak:
            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
                return mid;

            // If we are in the left:
            if (nums[mid] > nums[mid - 1]) low = mid + 1;

            // If we are in the right:
            // Or, arr[mid] is a common point:
            else high = mid - 1;
        }
        return -1;
        */
}
int main(){
   eff;
   int n;
   cin>>n;
   vector<int> nums(n);
   for(int i = 0; i < n; i++) cin>>nums[i];
   cout<<findPeakElement(nums)<<"\n";
   return 0;
}
