// Maximum Number of Events That Can Be Attended
// Problem link:
// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
// https://practice.geeksforgeeks.org/problems/ea8230731ccb057120bafb351c10c48b2d496125/1


// TC-> O(NlogN) | SC -> O(N)

#include<bits/stdc++.h>
using namespace std;

// Leetcode Solution: You can only attend one event at any time d
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // store deadlines of events in min heap to know the least deadline.
        priority_queue<int, vector<int>, greater<int>> pq;
        // sort the events according to the start day in the increasing order.
        sort(events.begin(), events.end());
        int i = 0, n = events.size(), ans = 0;
        for(int d = 1; d <= 100000; d++) {
            //remove the events that are already over
            while(!pq.empty() && pq.top() < d)
                pq.pop();
            // insert event's deadline that start at day d
            while(i < n && events[i][0] == d) {
                pq.push(events[i][1]);
                i++;
            }
            // schedule the event with least deadline on that day
            if(!pq.empty()) {
                pq.pop();
                ans++;
            }
            // when all events processed, then break
            if(pq.empty() && i == n) break;
	}
	    return ans;   
    }
};


// GFG Solution: You can attend only one event in a day.

class Solution {
  public:
    int maxEvents(int start[], int end[], int N) {
        unordered_set<int>s;
          vector<pair<int,int>> v;
          for(int i = 0; i<N; i++)
              v.push_back({start[i],end[i]});
          sort(v.begin(),v.end());
          for(int i=N-1;i>=0;i--){
              // if no booking is done for that particular day we will book the slot
                 if(s.find(v[i].second) == s.end())
                     s.insert(v[i].second);
                 else{
                     // if booking is done we check if any day befor that day is available
                    int e = v[i].second;
                    while(e >= v[i].first){
                        if(s.find(e) == s.end()){
                            s.insert(e);
                            break;
                        }
                        e--;}}}
            return s.size();
    }
};