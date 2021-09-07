// Given an integer array nums, return the maximum difference between two successive elements in its sorted form. 
// If the array contains less than two elements, return 0.

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

signed main(){
    eff;
    int n;
    cin>>n;
    vi nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];

        sort(nums.begin(),nums.end());
        int res = 0;
        if(nums.size() > 1)
        {    
            for(int i = 1; i < nums.size(); i++)
            {
                res = max(res,nums[i]-nums[i-1]);
            }
        }

    cout<<res;

    return 0;

}   

// Time complexity : O(nlogn)
// Space complexity: O(1)