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

    vi ans(n/2);
    int j = 0;
    
    ans[j++] = *min_element(v.begin(),v.begin()+x);  

    for(int i = x; i < n; i++)
    {
       ans[j++] = *min_element(v.begin()+i, v.begin()+(i-x));
    }
    cout<<1;
    for(int i = 0; i < ans.size(); i++)
    cout<<ans[i];
    return 0;
}