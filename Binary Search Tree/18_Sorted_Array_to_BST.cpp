// Sorted Array to Balanced BST
// Problem link: 
// https://practice.geeksforgeeks.org/problems/array-to-bst4443/1/#

#include<bits/stdc++.h>
using namespace std;

void convertToBST(vector<int> &nums, int start, int end, vector<int> &preorder)
{
        if(start > end) return;
        int mid = (start + end) >> 1;
        preorder.push_back(nums[mid]);
        convertToBST(nums, start, mid-1, preorder);
        convertToBST(nums, mid+1, end, preorder);
}
vector<int> sortedArrayToBST(vector<int>& nums) {
        vector<int> preorder;
        convertToBST(nums, 0, nums.size()-1, preorder);
        return preorder;
}

