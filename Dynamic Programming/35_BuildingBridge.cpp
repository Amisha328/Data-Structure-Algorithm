// Building Bridges
// Problem Statement - Variation of LIS
// Consider a 2 lane of cities with a horizontal river passing through its center. 
// There are n cities on the southern bank with x-coordinates a(1) … a(n) 
// and n cities on the northern bank with x-coordinates b(1) … b(n).
// You want to connect as many north-south pairs of cities as possible with bridges such that no two bridges cross. 
// When connecting cities, you can only connect city i on the northern bank to city i on the southern bank. 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   int lengthOfLIS(vector<int>& nums) 
   {
          int n = nums.size();
          int lis[n];
          lis[0] = 1;
          for(int i = 1; i < n; i++)
          {
                    lis[i] = 1;
                    for(int j = 0; j < i; j++)
                    {
                              if(nums[j] < nums[i])
                              lis[i] = max(lis[i], lis[j]+1);
                    }
          }
          return *max_element(lis, lis+n);
     }

     int maxBrides(vector<pair<int,int>> &cities)
     {
          int n = cities.size();
          sort(cities.begin(), cities.end());
          vector<int> bridges(n);
          for(int i = 0; i < n; i++)
                    bridges[i] = cities[i].second;
          int max_bridges = lengthOfLIS(bridges);
          
          return max_bridges;
     }
};

int main()
{
          Solution s;
          int n;
          cin>>n;
          vector<pair<int,int>> nums(n);
          for(int i = 0; i < n; i++)
              cin>>nums[i].first>>nums[i].second;
          
          cout << s.maxBrides(nums) << endl;
          return 0;
}
