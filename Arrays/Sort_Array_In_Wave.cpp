// Problem Statement
// Sort the array in such a way that the array looks like a wave array.

// example:
// Input: 2 3 1 4 3
// Output: 3 1 4 2 3 

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define vi vector<int>

signed main(){
    eff;
    int n;
    cin>>n;
    vi v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    for(int i = 0; i < n; i++)
    {
        if(i%2 == 0 && (v[i] < v[i+1]))
            swap(v[i], v[i+1]);
        if(i%2 == 1 && (v[i] > v[i+1]))
            swap(v[i], v[i+1]);    
    }  

    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    return 0;
}

// There could be many solutions possible for the same input set

// Time Complexity: O(n)
// Space Complexity: O(1)