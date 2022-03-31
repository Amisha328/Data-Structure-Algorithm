//  Sort Characters By Frequency
// https://leetcode.com/problems/sort-characters-by-frequency/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// TC->O(nlogn) | SC->O(n)
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i = 0; i < s.size(); i++)
            mp[s[i]]++;
        
         sort(s.begin(), s.end(), [&](char a, char b) -> bool {
           return (mp[a] != mp[b]? mp[a] > mp[b] : a < b);
        });
        
        return s;
    }
};
int main()
{
          string s;
          cin>>s;
          Solution obj;
          s = obj.frequencySort(s);
          cout<<s;
}