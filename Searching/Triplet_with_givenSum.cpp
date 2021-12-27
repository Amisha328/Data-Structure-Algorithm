// Problem Statement:
// Given an sorted array of integers, find if there is a triplet with sum equal to given sum ‘X’.

// Two pointer Approach

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

bool isPair(vi arr, int l, int r, int sum){
    while(l<r){
        if(arr[l]+arr[r]==sum){
            return true;
        }
        else if(arr[l]+arr[r]<sum){
            l++;
        }
        else{
            r--;
        }
    }
    return false;
}
signed main(){
    eff;
    int n;
    cin>>n;
    vi v(n);
    for(int i = 0; i < n; i++)
            cin>>v[i];

    int x;
    cin>>x;

    int f = 0;
    for(int i = 0; i < n ; i++)
    {
        // consider the current element as the first element and check if there is a pair with sum equal to x-v[i]
        if(isPair(v, i+1, n-1, x-v[i]))
        {
            if(v.find)
            cout<<"Yes"<<endl;
            f = 1;
            break;
        }
    }

    if(f==0)
        cout<<"No"<<endl;
    return 0;
}

// Time Complexity: O(n^2)
// Auxiliary Space: O(1)