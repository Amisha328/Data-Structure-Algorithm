// Number of Subsequences That Satisfy the Given Sum Condition
// Problem link:
// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9+7;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = n-1;
        vector<int> power_set(n, 1);
        for(int i = 1; i < n; i++){
            power_set[i] = (2*power_set[i-1]) % mod;
        }
        int l = 0, h = n-1;
        long long count = 0;
        while(l <= h){
            if(nums[l] + nums[h] <= target){
                count += power_set[h-l];
                l++;
            }
            else h--;
        }
        return count%mod;
    }
};