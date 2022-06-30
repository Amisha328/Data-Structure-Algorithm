// Minimum Moves to Equal Array Elements II
// Problem link:
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

/*
First Approach :
In this approach we just find the median after sorting the array which is nums[n/2] and add the absolute difference of the elements in the array with the median.

Time Complexity : O(n logn) for sort + O(n) for loop = O(n logn), Space complexity : O(1)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int minMoves = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());   // O(nlogn)
        int mid = nums[n/2];
        for(auto x: nums)
        {
            minMoves += abs(x - mid);
        }
        return minMoves;
    }
};

/*
Second Approach :
There is a function with syntax nth_element (RandomAccessIterator first, RandomAccessIterator nth, RandomAccessIterator last);
The function of this is that it rearranges the array in such a way such that the element at the nth position is the one which should be at that position if we sort the list from the first to last iterator. It uses the quick select method for this. For more details google it.

In this problem we don't need full array sorted we just need the median which is the n/2 th element in the sorted array. So this can be achived by nth_element(nums.begin(), nums.begin()+(n/2), nums.end()).
*/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int minMoves = 0;
        int n = nums.size();
        nth_element(nums.begin(), nums.begin()+(n/2), nums.end());  // O(n)
        int mid = nums[n/2];
        for(auto x: nums)
        {
            minMoves += abs(x - mid);
        }
        return minMoves;
    }
};