// K Closest Points To Origin
// Problme link:
// https://leetcode.com/problems/k-closest-points-to-origin/
// https://www.codingninjas.com/codestudio/problems/k-closest-points-to-origin_1094908#:~:text=For%20the%20first%20test%20case,and%20(%2D2%2C%202).

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> max_heap;
        for(auto x: points){
            auto d = pow(x[0], 2) + pow(x[1], 2);
            max_heap.push({d,{x[0],x[1]}});
            if(max_heap.size() > k)
                max_heap.pop();
        }
        
        vector<vector<int>> ans;
        while(!max_heap.empty()){
            ans.push_back({max_heap.top().second.first, max_heap.top().second.second});
            max_heap.pop();
        }
        return ans;
    }
};
