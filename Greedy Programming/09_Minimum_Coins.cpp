// Minimum Coins -  Greedy programming
// Problem link:
// https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1
// https://www.codingninjas.com/codestudio/problem-details/minimum-coins_982764

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector<int> ans;
        vector<int> arr =  { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        // int i = arr.size()-1;
        // while(i >= 0)
        // {
        //     if(N-arr[i] >= 0)
        //     {
        //         N -= arr[i];
        //         ans.push_back(arr[i]);
        //     }
        //     else if(arr[i] > N)
        //         i--;
        // }

        // OR - both works
        
        for(int i = arr.size()-1;i >= 0; i--){
            while(N >= arr[i])
            {
                ans.push_back(arr[i]);
                N -= arr[i];
            }
        }
        return ans;
    }
};