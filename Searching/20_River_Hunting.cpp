#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 



int main(){
          eff;
          int q;
          cin>>q;
          while(q--){
                    ll n;
                    cin>>n;
                    cout<<(ll)ceil(log2(n))<<endl;
          }
          return 0;
}