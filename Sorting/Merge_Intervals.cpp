// Merge Intervals
// Problem link:
// https://leetcode.com/problems/merge-intervals/
// https://practice.geeksforgeeks.org/problems/8a644e94faaa94968d8665ba9e0a80d1ae3e0a2d/1/#
// https://www.codingninjas.com/codestudio/problem-details/overlapping-intervals_630417
// https://www.codingninjas.com/codestudio/problems/merge-overlapping-intervals_1082151?leftPanelTab=0


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        sort(intervals.begin(), intervals.end());
        // take first interval in temp vector
        vector<int> tempInterval = intervals[0];
        for(auto it: intervals)
        {
            // if the start of current interval is leass or equal to the last of temp 
            // then can be merged
            // tempInterval = [1,3] and curr = [2,6]
            // 2 <= 3 then can be merged to [1,6]
            if(it[0] <= tempInterval[1])
                tempInterval[1] = max(it[1], tempInterval[1]);
            else
            {
                mergedIntervals.push_back(tempInterval);
                tempInterval = it;
            } 
        }
        mergedIntervals.push_back(tempInterval);
        return mergedIntervals;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
} 
