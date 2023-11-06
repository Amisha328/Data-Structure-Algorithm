//  https://www.codechef.com/practice/course/binary-search/INTBINS01/problems/SHKNUM?tab=statement

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 

int predicate(ll mid, int n){
         // cout<<"mid = "<<mid<<" n = "<<n<<endl;
          if(mid <= n) return 0;
          else return 1;
}
signed main(){
         eff;
          int t;
          cin>>t;
          while(t--){
                    int n;
                    cin>>n;
                    vector<int> arr;
                    for(int i = 0; i <= 30; i++){
                              for(int j = i+1; j <= 30; j++){
                                        // cout<<"i = "<<i<<" j = "<<j << endl;
                                        // cout<<"(1 << i) = "<<(1 << i)<<" (1 << j) = "<<(1 << j)<<endl;
                                        int val = (int)pow(2, i) + (int)pow(2, j);//(1ll << i) + (1ll << j);
                                       // cout<<"Val = "<<val<<endl;
                                        arr.push_back(val);
                              }
                    }
                    // for(auto x: arr) cout<<x<<" ";
                    // cout<<endl;
                    sort(arr.begin(), arr.end());
                    ll L = -1, R = arr.size();
                    while(L + 1 < R){
                             // cout<<"L = "<<L<<" R = "<<R;
                              ll M = L + (R - L)/2;
                             // cout<<" M = "<<M<<endl;
                              if(predicate(arr[M], n) == 0) L = M;
                              else R = M;
                    }
                   // cout<<"L = "<<L<<" R = "<<R<<endl;
                    cout<<min(abs(arr[L]-n), abs(arr[R]-n))<<endl;
          }
          return 0;
}