// Longest String Chain
// Problem link:
// https://leetcode.com/problems/longest-string-chain/description/
// https://practice.geeksforgeeks.org/problems/longest-string-chain/1?
// https://www.codingninjas.com/codestudio/problems/longest-string-chain_3752111?leftPanelTab=0

// TC -> O(N X N) + O(length of strings) + O(N logN)
// SC -> O(N)
#include <bits/stdc++.h> 
using namespace std;

class Solution {
private:
    bool checkPossible(string &s1, string &s2){
        if(s1.size() != s2.size() + 1) return false;
        int first = 0, second = 0;
        while(first < s1.size()){
                if(second < s2.size() && s1[first] == s2[second]){
                    first++;
                    second++;
                } else{
                    first++;
                }
        }
        if(first == s1.size() && second == s2.size()) return true;
        return false;
    }
    static bool cmp(string &s1, string &s2){
        return s1.size() < s2.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), cmp);
        vector<int> dp(n, 1);
        int maxi = 1;
        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(checkPossible(words[i], words[prev]) && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
            }
        }
        return maxi;
    }
};