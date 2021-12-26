// Search in Sorted Rotated Array

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

int findPos(vi &v, int l, int h, int x) 
{
        while(l <= h)
        {
            int mid = (l+h)/2;
            if(v[mid] == x)
                return mid;
            // check if left part is sorted
            if(v[l] <= v[mid])
            {
                // check if x lies in left half
                if(x >= v[l] && x < v[mid])
                {
                    h = mid-1;
                }
                else
                {
                    l = mid+1;
                }
            }
            else
            {
                // check if x lies in right half
                if(x > v[mid] && x <= v[h])
                    l = mid+1;
                else
                   h = mid-1;
            }
        }
        
        return -1;
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

    cout<<findPos(v, 0, n-1, x)<<endl;
    
    return 0;
}

// Time Complexity: O(log(n))
// Auxiliary Space: O(1)