// Course Schedule
// Problem link:
// https://leetcode.com/problems/course-schedule-iii/


#include<bits/stdc++.h>
using namespace std;

class Solution {
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // sort according to end-time
        sort(courses.begin(), courses.end(), cmp);
        int time = 0;
        priority_queue<int> max_heap;  // duration
        for(auto x: courses)
        {
            // add the course only when the duration for completing the course does not exceed its end value
            if(time+x[0] <= x[1])
            {
                max_heap.push(x[0]);
                time += x[0];
            }
            // if the duration to the top is greater than the current duration
            // remove the top duration and swap wit the current duration
            // adjust the time
            else if(max_heap.size() > 0 && max_heap.top() > x[0])
            {
                time += x[0] - max_heap.top();
                max_heap.pop();
                max_heap.push(x[0]);
            }
        }
        
        return max_heap.size();
    }
};