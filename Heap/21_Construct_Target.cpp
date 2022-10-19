//  Construct Target Array With Multiple Sums
// Problem link:
// https://leetcode.com/problems/construct-target-array-with-multiple-sums/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& target) {
        long int total_sum = 0;
        priority_queue<int> max_heap;
        
        for(auto x: target)
        {
            total_sum += x;
            max_heap.push(x);
        }
        
        while(max_heap.top() != 1)
        {
            int max_value = max_heap.top();
            max_heap.pop();
            long int difference_sum = total_sum - max_value;
            
            if(difference_sum == 1) return true;
            if(difference_sum > max_value || difference_sum == 0 || max_value % difference_sum == 0)
                return false;
            
            max_value %= difference_sum;
            total_sum = difference_sum + max_value;
            max_heap.push(max_value);
        }
        return true;
    }
};