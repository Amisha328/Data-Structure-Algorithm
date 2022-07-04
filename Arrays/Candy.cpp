// Problem links:
// https://leetcode.com/problems/candy/
// Explanation:
// https://rb.gy/uezwcf

#include<bits/stdc++.h>

class Solution {
public:
    int sum(int n){
        return (n*(n+1))/2;
    }
    /*
    // Method 1: TC-> O(N) | SC-> O(N)
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        
        // Left to Right
        for(int i = 1; i < n; i++)
        {
            if(ratings[i] > ratings[i-1])
                left[i] = left[i-1] + 1;
        }
        
        // Right to Left
        for(int i = n-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1])
                right[i] = right[i+1] + 1;
        }
        
        int candies = 0;
        for(int i = 0; i < n; i++)
            candies += max(left[i], right[i]);
        
        return candies;
    }
    */
    
    // Method 2: TC-> O(N) | SC-> O(1)
    int candy(vector<int>& ratings) {
        if(ratings.size() <= 1) return ratings.size();
        int up = 0, down = 0, candies = 0, prevSlope = 0;
        for(int i = 1; i < ratings.size(); i++){
            // increasing: +1, decreasing: -1, plain = 0
            int currSlope = (ratings[i] > ratings[i-1])? 1 : (ratings[i] < ratings[i-1])? -1 : 0;
            //                                 __ 
            // mountain changing: \_ || \/ || /
            if(prevSlope < 0 && currSlope >= 0  || prevSlope > 0 && currSlope == 0)
            {   candies += sum(up) + sum(down) + max(up, down);
                up = down = 0;
            }
            
            if(currSlope > 0) up++;
            else if(currSlope < 0) down++;
            else    candies++;
            
            prevSlope = currSlope;
                
        }
        candies += sum(up) + sum(down) + max(up, down) + 1;
        return candies;
    }
};