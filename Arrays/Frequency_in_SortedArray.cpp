// Frequencies in a Sorted Array
// Problem Statement:
// Given a sorted array of integers, find the frequency of all element in the array.

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

signed main(){
    eff;
    int n;
    cin>>n;
    vi A(n);
    for(int i=0;i<n;i++)
        cin>>A[i];

    // Naive solution
    /*
    int f = 1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==arr[i+1])
            f++;
        else
        {
            cout<<arr[i]<<" "<<f<<endl;
            f=1;
        }    
    } 
    */   

    // Efficient solution
    auto it = A.begin();
    while (it != A.end())
    {
        int val = *it;
 
        // find the first occurrence
        auto low = lower_bound(A.begin(), A.end(), val);
 
        // find the last occurrence
        auto high = upper_bound(A.begin(), A.end(), val);
 
        // print the difference(which gives frequency)
        cout<<val<<" "<<high - low<<"\n";
 
        // move the pointer to next element in the vector and not to immediate next
        it = it + (high-low);
    }
    return 0;
}

// Naive solution
// Time complexity: O(n)
// Space complexity: O(1) 

// Efficient solution
// Time complexity: O(log n)
// Space complexity: O(1)
