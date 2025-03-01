// Determine all the subsets
// This algorithm only works when n <= 20
// Problem link:
// https://leetcode.com/problems/subsets/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> subset;

        for(int i = 0; i < (1 << n); i++){
             vector<int> ls;
             for(int bits = 0; bits < n; bits++){
                 if(i & (1 << bits))
                    ls.push_back(nums[bits]);
             }
             subset.push_back(ls);
        }
        return subset;
  }
};

int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> nums(n);
          for(int i = 0; i < n; i++)
                    cin>>nums[i];
    	Solution ob;
    	vector<vector<int>> ans = ob.subsets(nums);
    	for(auto it: ans){
                    for(auto x: it){
                              cout<<x<<" ";
                    }
                    cout<<endl;
          }
    }
	return 0;
}