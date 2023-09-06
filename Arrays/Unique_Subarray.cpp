// Maximum Sum of Almost Unique Subarray
// Problem link:
// https://leetcode.com/contest/biweekly-contest-112/problems/maximum-sum-of-almost-unique-subarray/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
/*
       // Brute Force - TLE
        set<int> s;
        long long ans = 0;
        for(auto i = 0; i < nums.size()-k+1; i++){
            long long sum = 0;
            for(auto j = i; j < i+k; j++){
                sum += nums[j];
                s.insert(nums[j]);
            }
            //cout<<sum<<endl;
            if(s.size() < m)
                sum = 0;
            
            ans = max(ans, sum);
            s.clear();
        }
        return ans;
 */       

        // using sliding window technique
        
        map<int, int> mp;
        long long ans = 0, sum = 0;
        
        for(int i = 0; i < k; i++){
            sum += nums[i];
            mp[nums[i]]++;
        }
        
        if(mp.size() >= m)
            ans = max(ans, sum);
        
        for(int i = k; i < nums.size(); i++){
            // excluding the front element and including the new element
            sum += nums[i] - nums[i-k];
            mp[nums[i]]++;
            
            // if we reduce the count of the front elements and it reduces to zero
            // that means in the window of k size there is no elements nums[i-k] 
            // hence we can remove it from map.
            if(!--mp[nums[i-k]]) 
                mp.erase(nums[i-k]);
            
            if(mp.size() >= m)
                ans = max(ans, sum);
        }
        return ans;
    }
};