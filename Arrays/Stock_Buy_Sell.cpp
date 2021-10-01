// Stock Buy and Sell Problem
// Problem Statement:
// You are given an vay prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Print the maximum profit you can achieve from this transaction. If you cannot achieve any profit, print 0.

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

signed main(){
    eff;
    int n;
    cin>> n;
    vi v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];

    int sum = 0;
    for(int i = 1; i < n; i++)
    {
        if(v[i] > v[i-1])
            sum += v[i] - v[i-1];
    }    

    cout<<sum;

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)