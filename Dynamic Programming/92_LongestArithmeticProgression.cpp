// Longest Arithmetic Progression
// Problem link:
// https://practice.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// https://leetcode.com/problems/longest-arithmetic-subsequence/description/
// https://www.codingninjas.com/codestudio/problem-details/longest-ap_1235209

#include <bits/stdc++.h>
using namespace std;

// Recursive code:

class Solution{   
private:
    int solve(int A[], int index, int diff){
        if(index < 0) return 0;
        
        int ans = 0;
        // backward processing
        for(int j = index-1; j >= 0; j--){
            if(A[index]-A[j] == diff)
                ans = max(ans, 1 + solve(A, j, A[index]-A[j]));
        }
        return ans;
    }
public:
    int lengthOfLongestAP(int A[], int n) {
        if(n <= 2) return n;
        int ans = 0;
        for(int i = 0; i <n; i++){
            for(int j = i+1; j< n; j++){
                ans = max(ans, 2 + solve(A, i, A[j]-A[i]));
            }
        }
        return ans;
    }
};

// Memoization
// TC-> O(N^2) | SC-> O(N^2) + O(N)
class Solution{   
private:
    int solve(int A[], int index, int diff, unordered_map<int, int> dp[]){
        if(index < 0) return 0;
        if(dp[index].count(diff)) return dp[index][diff];
        
        int ans = 0;
        // backward processing
        for(int j = index-1; j >= 0; j--){
            if(A[index]-A[j] == diff)
                ans = max(ans, 1 + solve(A, j, A[index]-A[j], dp));
        }
        return dp[index][diff] = ans;
    }
public:
    int lengthOfLongestAP(int A[], int n) {
        if(n <= 2) return n;
        
        unordered_map<int, int> dp[n+1]; // [index] -> map{diff, len}
        
        int ans = 0;
        for(int i = 0; i <n; i++){
            for(int j = i+1; j< n; j++){
                ans = max(ans, 2 + solve(A, i, A[j]-A[i], dp));
            }
        }
        return ans;
    }
};

// Tabulation:
// TC-> O(N^2) | SC-> O(N^2)
class Solution{ 
public:
    int lengthOfLongestAP(int A[], int n) {
        if(n <= 2) return n;
        unordered_map<int, int> dp[n+1]; // [index] -> map{diff, len}

        int ans = 0;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                int diff = A[i]-A[j];
                int cnt = 1; // count the initial ith element
                // if length with this diff is already present till jth index
                if(dp[j].count(diff)) 
                    cnt = dp[j][diff];
                
                dp[i][diff] = 1 + cnt; // jth element that we include for that we do +1 here
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};