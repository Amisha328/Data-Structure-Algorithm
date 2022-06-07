// Merge Sorted Array
// Problem link:
// https://leetcode.com/problems/merge-sorted-array/
// https://www.codingninjas.com/codestudio/problems/ninja-and-sorted-arrays_1214628?topList=striver-sde-sheet-problems&leftPanelTab=0

// Explanation:
// https://rb.gy/hig7vf

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
         int i = m - 1, j = n - 1, k = m + n - 1;
         while(i >= 0 && j >= 0) 
         {
             if(nums1[i] > nums2[j])
                 nums1[k--] = nums1[i--];
             else
                 nums1[k--] = nums2[j--];
         }
         while(j >= 0) {
             nums1[k--] = nums2[j--];
         }
    }
};