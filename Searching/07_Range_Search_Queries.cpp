// Range Search Queries
/*
You are given an array of n integers and q queries. In each query, you are given 2 integers l and r. 
You need to report the number of array elements having value between l and r.
*/

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

// Using the Super templet to find the first occurance of value l.
int predicateFirst(ll val, ll X){
          if(val < X) return 0;
          return 1;
}
// Using the Super templet to find the last occurance of value r.
int predicateLast(ll val, ll X){
          if(val <= X) return 0;
          return 1;
}
int findFirstOccurance(int N, vector<ll> &arr, ll X){
          int L = -1, R = N;
          while( L + 1 < R){
                    int M = L + (R - L)/2;
                    if(predicateFirst(arr[M], X) == 0) L = M;
                    else R = M;
          }
          return R;
}
int findLastOccurance(int N, vector<ll> &arr, ll X){
          int L = -1, R = N;
          while( L + 1 < R){
                    int M = L + (R - L)/2;
                    if(predicateLast(arr[M], X) == 0) L = M;
                    else R = M;
          }
          return L;
}
int main(){
          eff;
          int n, q;
          cin>>n>>q;
          vector<ll> arr(n);
          for(int i = 0; i < n; i++) cin>>arr[i];
          sort(arr.begin(), arr.end());
          while(q--){
                    ll l, r;
                    cin>>l>>r;
                    int first = findFirstOccurance(n, arr, l);
                    int last = findLastOccurance(n, arr, r);
                    cout<<(last-first)+1<<" ";
          }
          return 0;
}