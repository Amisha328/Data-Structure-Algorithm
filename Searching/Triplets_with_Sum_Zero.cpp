// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> ans;
    int n = nums.size();
    if(n < 3) return {};
    sort(nums.begin(), nums.end());
    vector<int> temp;
    set<vector<int>>s;
    for(int i = 0; i < n; i++)
    {
        int l = i+1, r = n-1;
        while(l < r)
        {
            if(nums[i] + nums[l] + nums[r] == 0)
            {
                temp = {nums[i], nums[l], nums[r]};
                if(s.find(temp) == s.end())
                {
                    ans.push_back(temp);
                    s.insert(temp);
                }
                l++;
            }
            else if(nums[i] + nums[l] + nums[r] < 0)
                l++;
            else
                r--;
        }
    }
    
    return ans;

}
signed main(){
    eff;
    int n;
    cin>>n;
    vi v(n);
    for(int i = 0; i < n; i++)
         cin>>v[i];


    vector<vector<int>> ans = threeSum(v);
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}