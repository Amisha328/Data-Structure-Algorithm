// Continuous Subarray Sum
// Problem link:
// https://leetcode.com/problems/continuous-subarray-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // Brute Force - TLE
        // if(nums.size() == 1) return false;
        // for(int i = 0; i <= nums.size()-2; i++)
        // {
        //     int sum = nums[i];
        //     for(int j = i+1; j < nums.size(); j++)
        //     {
        //         sum += nums[j];
        //         //cout<<"sum = "<<sum<<endl;
        //         if(sum % k == 0) return true;
        //     }
        // }
        // return false;
        
        long long sum = nums[0];
        for(int i = 1;i < nums.size(); i++){
            if(nums[i] == nums[i-1])
                if(nums[i] == 0)
                    return true;
            sum += nums[i];
            //cout<<"sum = "<<sum <<endl;
            if(sum % k == 0)
                return true;
            int j = 0;
            int temp = sum;
            while((i-j) > 1 && temp >= k){
                //cout<<"j = "<<j<<" ";
                temp -= nums[j++];
                cout<<"temp = "<<temp<<endl;
                if(temp % k == 0)
                    return true;
            }
        }
        return false;
        
        // unordered_map<int, int> mp;
        // mp[0] = -1;
        // int sum = 0;
        // for(int i = 0; i < nums.size(); i++)
        // {
        //     sum += nums[i];
        //     sum %= k;
        //     if(mp.find(sum) != mp.end())
        //     {
        //         if((i - mp[sum]) > 1) return true;
        //     }
        //     else
        //         mp[sum] = i;
        // }
        // return false;
    }
};