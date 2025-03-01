// Remove All Adjacent Duplicates In String
// Problem link:
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        for(auto i: s)
        {
            if(!ans.empty() and ans.back()==i)
                ans.pop_back();
            else
                ans.push_back(i);
        }
        return ans;
    }
};