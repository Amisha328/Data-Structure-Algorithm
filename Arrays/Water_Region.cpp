/*
1. Given n non-negative integers a1, a2, ..., an. 
 2. Each represents a point at coordinate (i, ai). 
 3. "n" vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). 
 4. Find two lines, which, together with the x-axis forms a region, such that the region contains the most water.
 Note : that you may not slant the container.

Constraints
1. n == height.length
2. 2 <= n <= 105
3. 0 <= height[i] <= 104

Format
Input
1. Take 'n', size of Array
2. Take 'n' different element for Array

Output
1. Max water 
*/


// Problem link:
// https://leetcode.com/problems/container-with-most-water/submissions/

#include<bits/stdc++.h>
using namespace std;

int main(){
    // write your code here
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];
    
    int l = 0, r = n-1;
    int water = 0;
    while(l < r)
    {
        water = max(water , min(v[l], v[r]) * (r-l));
        if(v[l] < v[r]) l++;
        else r--;
    }
    cout<<water<<endl;
    return 0;
}
