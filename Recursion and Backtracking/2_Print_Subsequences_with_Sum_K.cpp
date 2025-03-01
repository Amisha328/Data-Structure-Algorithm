// Print Subsequences with sum K

#include<bits/stdc++.h>
using namespace std;


void printSubsequence(vector<int> &nums, int idx, int n, vector<int> &temp, int s, int &sum){
          if(idx == n){
                    if(s == sum){
                              for(auto it: temp)
                                        cout<<it<<" ";
                              cout<<endl;        
                    }
                    return;
          }  
          // take        
          temp.push_back(nums[idx]);
          s += nums[idx];
          printSubsequence(nums, idx+1, n, temp, s, sum);
          // not - take
          temp.pop_back();
          s -= nums[idx];
          printSubsequence(nums, idx+1, n, temp, s, sum);
}

signed main(){
          int n, sum;
          cin>>n>>sum;
          vector<int> nums(n);
          for(int i = 0; i < n; i++) cin>>nums[i];
          vector<int> temp;
          printSubsequence(nums, 0, n, temp, 0, sum);
          return 0;
}