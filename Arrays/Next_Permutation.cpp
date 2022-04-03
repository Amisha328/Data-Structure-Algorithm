// Next Permutation
// Problem link:
// https://leetcode.com/problems/next-permutation/
// https://practice.geeksforgeeks.org/problems/next-permutation5226/1
// https://www.codingninjas.com/codestudio/problem-details/next-permutaion_893046

// TC -> O(nlogn)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int x = -1, y = -1;
		
		// forwards traversal
        for(int i = 0; i < n-1; i++)   
            if(nums[i] < nums[i+1]) 
                x = i;
        
        // x will remain -1 only if the array is sorted in descending order
        if(x == -1)
        {
            // sort in ascending order - O(nlogn)
            sort(nums.begin(), nums.end());
            return ;
        }
		
        // forward traversal 
        for(int i = x+1; i < n; i++) 
            if(nums[x] < nums[i]) 
                y = i;
        
        swap(nums[x], nums[y]);
        
        reverse(nums.begin()+x+1, nums.end());
    }
};

// TC -> O(n)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int x = -1, y = -1;
		
		// backward traversal
        for(int i = n-2; i >= 0; i--) 
        {
            if(nums[i] < nums[i+1]) 
            {
                x = i;
                break;
            }
        }
        
        // x will remain -1 only if the array is sorted in descending order
        if(x == -1)
        {
            // reverse the array to make it forward sorted -> O(n)
            reverse(nums.begin(), nums.end());
            return ;
        }
        
		// backward traversal
        for(int i = n-1; i >= x; i--) 
            if(nums[x] < nums[i]) 
            {
                y = i;
                break;
            }
        
        swap(nums[x], nums[y]);
        
        reverse(nums.begin()+x+1, nums.end());
    }
};
