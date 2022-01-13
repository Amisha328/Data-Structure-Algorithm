// N-bonacci numbers - is the a fibbonacci sequence of numbers where each number is the sum of the previous n numbers.

// Probelem statement:
// print the first m, N-bonacci numbers.

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

signed main(){
    eff;
    int n,m;
    cin>>n>>m;

    int sum = 1;
    vi v(m,0);
    v[n-1] = 1;
    v[n] = 1;

    for(int i = n+1; i < m; i++)
    {
        v[i] = sum + v[i-1] - v[i-n-1];
        sum = v[i];
    }

    for(int i=0;i<m;i++)
        cout<<v[i]<<" ";
    
    return 0;
}

// Time Complexity: O(m)
// Space Complexity: O(m)