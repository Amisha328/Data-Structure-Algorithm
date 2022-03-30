// Take two sorted arrays and merge them.
// a[] = {10,20,30}
// b[] = {5,50,50}
// Output: {5,10,20,30,50,50}

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

signed main(){
    eff;
    int n,m;
    cin>>n>>m;
    vi a(n);
    for(int i = 0; i < n; i++)
        cin>>a[i];
    vi b(m);
    for(int i = 0; i < m; i++)
        cin>>b[i];

    int i = 0, j = 0;
    while(i < n && j < m)
    {
        if(a[i] <= b[j])
        {
            cout<<a[i]<<" ";
            i++;
        }
        else
        {
            cout<<b[j]<<" ";
            j++;
        }
    }

    while(i < n)
    {
        cout<<a[i]<<" ";
        i++;
    }

    while(j < m)
    {
        cout<<b[j]<<" ";
        j++;
    }
    return 0;
}

// Time Complexity: O(n+m)
// Auxiliary Space: O(1)