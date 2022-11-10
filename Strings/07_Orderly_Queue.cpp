// Orderly Queue
// Problem link: https://leetcode.com/problems/orderly-queue/

/*
Problem statement:
You are given a string s and an integer k. You can choose one of the first k letters of s and append it at the end of the string..
Return the lexicographically smallest string you could have after applying the mentioned step any number of moves.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string orderlyQueue(string s, int k) {
        // k = 1, we can just basically rotate the array unless we get to the smallest lexicographical order.
        if(k == 1){
            string ans = s;
            for(int i = 0; i < s.size(); i++){
                string temp = s.substr(i) + s.substr(0, i);
                if(temp < ans)
                    ans = temp;
            }
            return ans;
        // K >= 2, we can swap two unsorted elements same as in bubble sort
        } else{
            sort(s.begin(), s.end());
            return s;
        }
    }
};