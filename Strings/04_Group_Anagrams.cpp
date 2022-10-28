//  Group Anagrams
// Problem link:
// https://leetcode.com/problems/group-anagrams/

#include <bits/stdc++.h>
using namespace std;

// Intution:
// Use an unordered_map to group the strings by their sorted counterparts. 
// Use the sorted string as the key and all anagram strings as the value.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto it: strs){
            string val = it;
            sort(val.begin(), val.end());
            mp[val].push_back(it);
        }
        
        vector<vector<string>> ans;
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};

int main()
{
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    Solution obj;
    vector<vector<string>> ans = obj.groupAnagrams(strs);
    for(auto x: ans){
          for(auto y: x){
                    cout<<y<<" ";
          }
          cout<<endl;
    }
    return 0;
}