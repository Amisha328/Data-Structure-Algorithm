// Determine if a Cell Is Reachable at a Given Time
// Problem link:
// https://leetcode.com/contest/weekly-contest-362/problems/determine-if-a-cell-is-reachable-at-a-given-time/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dx = abs(fx - sx);
        int dy = abs(fy - sy);
        
        // if the start and end is the same and t == 1
        if(dx == 0 && dy == 0 && t == 1) return false;
        
        // diagonal comman distance + extra distance
        return (min(dx, dy) + abs(dx - dy)) <= t;
    }
};