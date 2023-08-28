// Find the Minimum Possible Sum of a Beautiful Array
// Problem link:
// https://leetcode.com/contest/weekly-contest-360/problems/find-the-minimum-possible-sum-of-a-beautiful-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        set<long long> s;
        long long x = 1, ans = 0;
        for(int i = 1; i <= n; i++){
            while(s.count(x)) x++;
            ans += x;
            s.insert(x);
            s.insert(target-x);
        }
        return ans;
    }
};