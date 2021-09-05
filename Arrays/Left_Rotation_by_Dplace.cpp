// Left Rotate an Array by d places
// example:
// Input: arr[] = {1, 2, 3, 4, 5, 6, 7}
//        d = 2
// Output: arr[] = {3, 4, 5, 6, 7, 1, 2}

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

signed main(){
    eff;
    int n,d;
    cin>>n>>d;
    vi v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    // Naive Approach
    // while(d--)
    // {
    //     for(int i = 0; i < n-1; i++)
    //     {
    //         swap(v[i],v[i+1]);
    //     }    
    // }

    // Efficient Approach
    // int temp[d];
    // for(int i=0;i<d;i++)
    //     temp[i]=v[i];   

    // for(int i=d;i<n;i++)
    //     v[i-d]=v[i];

    // for(int i=0;i<d;i++)
    //     v[n-d+i]=temp[i];

    // More Efficient Approach
    // Reversal Approach
    // 1. Reverse the first d elements
    // 2. Reverse the last n-d elements
    // 3. Reverse the whole array

    reverse(v.begin(),v.begin()+d);
    reverse(v.begin()+d,v.end());
    reverse(v.begin(),v.end());

    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    return 0;
}

// naive solution
// Time Complexity: O(n*d)
// Space Complexity: O(1)

// Efficient Solution
// Time Complexity: O(n)
// Space Complexity: O(d)

// More Efficient Solution
// Time Complexity: O(n)
// Space Complexity: O(1)
   