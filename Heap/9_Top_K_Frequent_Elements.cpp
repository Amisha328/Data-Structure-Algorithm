// Top K Frequent Elements
// Problem link:
// https://leetcode.com/problems/top-k-frequent-elements/
// https://practice.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1#
// https://www.codingninjas.com/codestudio/problem-details/k-most-frequent-elements_3167808

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        unordered_map<int, int> freq; // freq,element
        // O(n)
        for(auto &x: nums)
            freq[x]++;
        
        
        // O(nlogk)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for(auto &it: freq){
            min_heap.push({it.second, it.first});
            if(min_heap.size() > k)
                min_heap.pop();
        }
        
        vector<int> ans;
        while(!min_heap.empty()){
            ans.emplace_back(min_heap.top().second);
            min_heap.pop();
        }
        
        // O(k)
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}  