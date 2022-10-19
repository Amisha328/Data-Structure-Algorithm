// Frequency Sort
// problem link:
// https://leetcode.com/problems/sort-array-by-increasing-frequency/
// https://practice.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency-1587115621/1/#

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;

        // Min-Heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for(auto &it: mp){
            // if the frequency of nay two elements gets same then if the larger value is negated it gets smallest value and it is at the top. Hence, can be sorted in decreasing order.
            min_heap.push({it.second, -1 * it.first});
        }
        
        int x = 0;
        while(!min_heap.empty()){
            int f = min_heap.top().first;
            int e = -1 * min_heap.top().second;
            for(int i = 1; i <= f; i++)
                nums[x++] = e;
            min_heap.pop();
        }
        
        return nums;
    }
};