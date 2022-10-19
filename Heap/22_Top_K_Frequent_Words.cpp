// Top K Frequent Words
// Problem link:
// https://leetcode.com/problems/top-k-frequent-words/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct compare{
        // sorted by the frequency from highest to lowest.
        // same frequency then sort by their lexicographical order.
        bool operator()(pair<string,int>& a, pair<string,int>& b){
          return a.second > b.second || (a.second == b.second && a.first < b.first);
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for(auto x: words){
            freq[x]++;
        }
        
        priority_queue<pair<string,int>, vector<pair<string,int>>, compare> min_heap;
        for(auto &it: freq){
            min_heap.push(it);
            if(min_heap.size() > k){
                min_heap.pop();
            }
        }
        
        vector<string> ans;
        while(!min_heap.empty()){
            ans.push_back(min_heap.top().first);
            min_heap.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};