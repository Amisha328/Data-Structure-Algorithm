// N meetings in one room
// Problem link:
// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
// https://www.codingninjas.com/codestudio/problem-details/maximum-meetings_1062658

#include <bits/stdc++.h> 
using namespace std;

struct Meeting
{
    int start;
    int end;
    int pos;
};
static bool compare(Meeting m1, Meeting m2)
{
    if(m1.end < m2.end) return true;
    else if(m1.end > m2.end) return false;
    else if(m1.pos < m2.pos) return true;
    else return false;
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();
    Meeting arr[n];
    for(int i = 0; i < n; i++)
    {
        arr[i].start = start[i];
        arr[i].end = end[i];
        arr[i].pos = i+1;
    }
    sort(arr, arr+n, compare);
    
    vector<int> ans;
    ans.push_back(arr[0].pos);
    int limit = arr[0].end;
    for(int i = 1; i < n; i++)
    {
        if(arr[i].start > limit)
        {
            ans.push_back(arr[i].pos);
            limit = arr[i].end;
        }
    }
    return ans;
}