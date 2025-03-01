// Check if Strings Can be Made Equal With Operations II
// Problem link:
// https://leetcode.com/contest/biweekly-contest-112/problems/check-if-strings-can-be-made-equal-with-operations-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(string &s){
        int n = s.size();
        string a, b;
        for(int i = 0; i < s.size(); i++){
            if(i & 1) a.push_back(s[i]);
            else b.push_back(s[i]);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a+b;
    }
    bool checkStrings(string s1, string s2) {
        string a = solve(s1);
        string b = solve(s2);
        return a==b;
    }
};