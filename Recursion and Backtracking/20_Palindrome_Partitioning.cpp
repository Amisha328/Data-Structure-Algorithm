// Palindrome Partitioning
// Problem link:
// https://leetcode.com/problems/palindrome-partitioning/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isPalindrome(string s, int start, int end)
    {
        while(start <= end)
        {
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    void solve(string s, vector<vector<string>> &ans, vector<string> &sol, int index)
    {
        if(index == s.size())
        {
            ans.push_back(sol);
            return;
        }
        
        for(int i = index; i < s.size(); i++)
        {
            if(isPalindrome(s, index, i))
            {
                sol.push_back(s.substr(index, i-index+1)); // substr(pos, len)
                solve(s, ans, sol, i+1);
                sol.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> sol;
        solve(s, ans, sol, 0);
        return ans;
    }
};