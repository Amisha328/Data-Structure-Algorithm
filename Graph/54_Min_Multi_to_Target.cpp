// Minimum Multiplications to reach End
// Problem link:
// https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1?

//  Dijakstra's Algorithm

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
       queue<pair<int, int>> q;
       vector<int> dist(100000, 1e9); // taking 1 to 1e5 as the nodes
       int mode = 100000;
       q.push({start, 0}); // {node, steps}
       
       while(!q.empty())
       {
           auto it = q.front();
           q.pop();
           int node = it.first;
           int steps = it.second;
           
           for(auto x: arr)
           {
               // mod to keep number in range (1, 1e5)
               int nums = (x * node) % mode;
               if(steps + 1 < dist[nums]){
                   // if better soltuion possible with min steps
                   dist[nums] = steps + 1;
                   if(nums == end) return steps+1;
                   q.push({nums, steps+1});
               }
           }
       }
       return -1;  // imposible to get target
    }
};
