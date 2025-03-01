// Minimum Platforms
// Problem link:
// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
// https://www.codingninjas.com/codestudio/problem-details/minimum-number-of-platforms_799400

#include<bits/stdc++.h>
using namespace std;

int calculateMinPatforms(int at[], int dt[], int n) {
        sort(at, at+n);
        sort(dt, dt+n);
        
        int i = 1, j = 0;
        int max_platform = 1;
        int needed_platform = 1;
        while(i < n && j < n)
        {
            if(at[i] <= dt[j])
            {
                i++;
                max_platform++;
            }
            else if(dt[j] < at[i])
            {
                j++;
                max_platform--;
            }
            needed_platform = max(needed_platform, max_platform);
        }
        return needed_platform;
}