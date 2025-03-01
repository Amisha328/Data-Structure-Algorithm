// Russian Doll Envelopes
// Problem link:
// https://leetcode.com/problems/russian-doll-envelopes/
// https://www.codingninjas.com/codestudio/problems/russian-doll-envelopes_1094905?leftPanelTab=0


#include <bits/stdc++.h>
using namespace std;

// Binary Search - Longest Increasing Subsequenece on height part
// TC -> O(NlogN) | SC-> O(N)

class Solution {
private:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0]){
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        int n = envelopes.size();
        if(n == 0) return 0;
        vector<int> ans;
        ans.push_back(envelopes[0][1]);
        for(int i = 1; i < n; i++){
            if(envelopes[i][1] > ans.back())
                ans.push_back(envelopes[i][1]);
            
            int index = lower_bound(ans.begin(), ans.end(), envelopes[i][1]) - ans.begin();
            ans[index] = envelopes[i][1];
        }
        return ans.size();
    }
};