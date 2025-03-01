// Kth Permutation Sequence
// Problem link:
// https://leetcode.com/problems/permutation-sequence/
// https://practice.geeksforgeeks.org/problems/find-kth-permutation/1
// https://www.codingninjas.com/codestudio/problem-details/k-th-permutation-sequence_1112626

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;
        for(int i = 1; i < n; i++)
        {
            fact = fact * i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        string ans = "";
        k = k-1;
        while(true)
        {
            ans += to_string(numbers[k/fact]);
            numbers.erase(numbers.begin()+k/fact);
            if(numbers.size() == 0) break;
            k = k % fact;
            fact = fact / numbers.size();
        }
        return ans;
    }
};
