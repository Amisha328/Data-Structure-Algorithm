// Sort Array by Increasing Frequency
// https://leetcode.com/problems/sort-array-by-increasing-frequency/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
          // TC->O(nlogn) | Sc->O(n)
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        
        // Using Lamba function to sort
        // Lamda: [&] (parameter) { Expression }
        // Take two elements from nums array and compare their frequency in mp
        // if frequency is not equal return elemet with lower frequency
        // if equal then return the greater element
        sort(nums.begin(), nums.end(), [&](int a, int b) -> bool {
           return (mp[a] != mp[b]? mp[a] < mp[b] : a > b);
        });
        
        return nums;
    }
};

int main()
{
          int n;
          cin>>n;
          vector<int> arr(n);
          for(int i = 0; i < n; i++)
                    cin>>arr[i];
          Solution obj;
          arr = obj.frequencySort(arr);
          for(auto x: arr)
              cout<<x<<" ";
}