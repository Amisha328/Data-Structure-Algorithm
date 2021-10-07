// Find maximum sum of k consecutive elements using Sliding Window technique

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

signed main(){
    eff;
    int n,k;
    cin>>n>>k;
    vi v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];

    int curr_sum = 0, sum = 0;
    for(int i = 0; i < k; i++)
    {
         curr_sum += v[i];
    }
    sum = curr_sum;
    for(int i = k; i < n; i++)
    {
        curr_sum += v[i] - v[i-k];
        sum = max(sum, curr_sum);
    }

    cout<<sum;
    return 0;
}

// Time Complexity: θ(n)
// Auxiliary Space: O(1)