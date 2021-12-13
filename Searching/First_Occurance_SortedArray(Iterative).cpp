// Index of first Occurrence in Sorted
// Given a sorted array with repetition and an element x, we need to find index of first occurrence of x.

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

signed main(){
    eff;
    int n;
    cin>>n;
    vi v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];

    int x;
    cin>>x;

    int l = 0, r = n-1;
    int mid;
    while(l <= r){
        mid = (l+r)/2;
        if(v[mid] == x)
        {
            if(mid == 0 || v[mid-1] != x)
                break;
            else
                r = mid-1;
        }
        else if(v[mid] > x)
            r = mid-1;
        else
            l = mid+1;
    }
    if(v[mid] == x)
        cout<<mid<<endl;
    else
        cout<<-1<<endl;
    return 0;
}

// Time Complexity: O(log(n))
// Auxiliary Space: O(1)