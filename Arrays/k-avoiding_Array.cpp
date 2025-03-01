// Determine the Minimum Sum of a k-avoiding Array
// Problem link:
// https://leetcode.com/contest/weekly-contest-359/problems/determine-the-minimum-sum-of-a-k-avoiding-array/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSum(int n, int k) {
        int x = 1, i = 1;
        set<int> s;
        while(i <= n){
            if(s.count(k-x)) x++;
            else{
                 s.insert(x);
                 x++;
                 i++;
            }
        }
        // for (auto itr = s.begin(); itr != s.end(); itr++) {
        //     cout << *itr << " ";
        // }
        // cout << endl;
        return accumulate(s.begin(), s.end(), 0);
    }
};

// Input: (n,k)