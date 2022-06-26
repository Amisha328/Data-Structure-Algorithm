// Maximum Points You Can Obtain from Cards
// Explantion: https://rb.gy/ubqd8v
// Problem link:
// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // Prefix Sum
        int n = cardPoints.size();
        
        vector<int> prefix_sum(n+1);
        
        prefix_sum[1] = cardPoints[0];
        for(int i = 1; i < n; i++)
        {
            prefix_sum[i+1] =  prefix_sum[i] + cardPoints[i];
        }
        
        int middle_sum = prefix_sum[n];
        for(int i = n-k; i <= n; i++)
        {
            middle_sum = min(middle_sum, prefix_sum[i]-prefix_sum[i-(n-k)]);
        }
        
        return prefix_sum[n]-middle_sum;
        
        
        /*
        // Sliding Window

        int l = 0, r = n-k;
        int tot_sum = accumulate(cardPoints.begin()+r, cardPoints.end(), 0LL);
        int sum = tot_sum;
        while(k--)
        {
            tot_sum += cardPoints[l++] - cardPoints[r++];
            sum = max(sum, tot_sum);
        }
        return sum;
       */ 
    }
};

/*
[1,2,3,4,5,6,1]
3
[2,2,2]
2
[9,7,7,9,7,7,9]
7
[100,40,17,9,73,75]
3
[11,49,100,20,86,29,72]
4
[96,90,41,82,39,74,64,50,30]
8
*/