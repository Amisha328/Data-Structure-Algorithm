#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define vi vector<int>

signed main(){
    eff;
    int n;
    cin>>n;
    vi v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int max=v[0];
    for(int i=1;i<n;i++){
        if(v[i]>max){
            max=v[i];
        }
    }
    cout<<max;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)