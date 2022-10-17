//  Minimum Time to Make Rope Colorful
// Problem link:
// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        /*  To minimize the time of subtracting a character from the array(removing a balloon), the character that will stay in the string will be the one with the largest time.
So by adding up the costs(sum_time) and keeping track of the index with the highest time(max_time), when the character changes, we will only need to subtract the sum with the largest time that will stay in the string.
On the other hand, if there are no repeated characters in a row, res will not be added at all because max_time and sum_time will be the same and res will be added zero.*/
        
        int sum_time = 0, max_time = 0;
        int res = 0;
        for(int i = 0; i < colors.size(); i++)
        {
            if(i > 0 && colors[i] != colors[i-1])
            {
                res += sum_time - max_time;
                sum_time = max_time = 0;
            }
            
            sum_time += neededTime[i];
            max_time = max(max_time, neededTime[i]);
        }
        res += sum_time - max_time;
        return res;
    }
};