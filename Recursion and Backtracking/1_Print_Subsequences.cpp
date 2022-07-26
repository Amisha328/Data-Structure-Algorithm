// Print Subsequences/ Subsets
// Problem links:
// https://www.codingninjas.com/codestudio/problems/print-subsequences_624391
// https://leetcode.com/problems/subsets/

#include <bits/stdc++.h>
void solve(char input[], int n, int idx, string &s){
    if(idx == n){  
        cout<<s<<endl;
        return;
    }
    // take
    s.push_back(input[idx]);
    solve(input, n, idx+1, s);
    // not take
    s.pop_back();
    solve(input, n, idx+1, s);
}
void printSubsequences(char input[]) {
    string s;
    int len = 0;
    while(input[len] != '\0')
        len++;
    
    solve(input, len, 0, s);
}
