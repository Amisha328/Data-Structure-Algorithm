// Leader in Array
// An element is called the leader of an array if there is no element greater than it on the right side.
// example:
// arr[] = {7, 10, 4, 3, 6,	5, 2}
// o/p:  10  6   5  2

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

signed main(){
    eff;
    int n;
    cin>>n;
    vi v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    vi t;
    int max_leader = v[n-1];
    t.push_back(max_leader);
    for(int i = n-2; i >= 0; i--)
    {
        if(v[i] > max_leader)
        {
            max_leader = v[i];
            t.push_back(max_leader);
        }
    }

    reverse(t.begin(), t.end());

    for(int i = 0; i < t.size(); i++)
        cout<<t[i]<<" ";

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)