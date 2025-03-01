// Check if subsequence exist

#include<bits/stdc++.h>
using namespace std;

bool printSubsequence(vector<int> &nums, int idx, int n, int s, int &sum){
          if(idx == n){
                    if(s == sum){
                              return true;  
                    }
                    else
                              return false;
          }  
          // take        
          s += nums[idx];
          if(printSubsequence(nums, idx+1, n, s, sum)) return true;
          // not - take
          s -= nums[idx];
          if(printSubsequence(nums, idx+1, n, s, sum)) return true;
          return false;
}

signed main(){
          int n, sum;
          cin>>n>>sum;
          vector<int> nums(n);
          for(int i = 0; i < n; i++) cin>>nums[i];
          cout<<printSubsequence(nums, 0, n, 0, sum);
          return 0;
}