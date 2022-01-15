// Right Rotate an Array by d places
// example1:
// Input: arr[] = {1, 2, 3, 4, 5, 6, 7}
//        d = 3
// Output: arr[] = {5, 6, 7, 1, 2, 3, 4}

// example2:
// Input: arr[] = {-1, -100, 3, 99}
//        d = 2
// Output: arr[] = {3, 99, -1, -100}

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

    d = d % n;
    reverse(v.begin()+(n-d),v.end());
    reverse(v.begin(),v.begin()+(n-d));
    reverse(v.begin(),v.end());   

     for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)