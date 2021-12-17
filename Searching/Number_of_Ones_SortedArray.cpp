// Count 1s in a Sorted Binary Array
// Given a sorted binary array, we need to count 1s in this array. 

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

int countOnes(vi &v, int n)
{
    int l = 0, r = n-1;
    while(l <= r)
    {
        int mid = (l+r)/2;
        if(v[mid] == 1)
        {
            if(mid == 0 || v[mid-1] == 0)
              return (n-mid);
            else
                r = mid -1;
        }
        else if(v[mid] == 0)
             l = mid + 1;           
    }
    return 0;
}

signed main(){
    eff;
    int n;
    cin>>n;
    vi v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];

    cout<<countOnes(v, n)<<endl;
    
    return 0;
}

// Time Complexity: O(log(n))
// Auxiliary Space: O(1)
