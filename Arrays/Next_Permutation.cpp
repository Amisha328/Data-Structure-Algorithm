// Next Permutation
// Problem link:
// https://leetcode.com/problems/next-permutation/
// https://practice.geeksforgeeks.org/problems/next-permutation5226/1

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int x = -1, y = -1;
        for(int i = 0; i < n-1; i++) 
            if(nums[i] < nums[i+1]) 
                x = i;
        
        // x will remain -1 only if the array is sorted in descending order
        if(x == -1)
        {
            // sort in ascending order
            sort(nums.begin(), nums.end());
            return ;
        }
        
        for(int i = x+1; i < n; i++) 
            if(nums[x] < nums[i]) 
                y = i;
        
        swap(nums[x], nums[y]);
        
        reverse(nums.begin()+x+1, nums.end());
    }
};
