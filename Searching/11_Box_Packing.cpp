// Box Packing
/*
There are n rectangular boxes of the same size: w in width and h in length. 
You are required to find a square of the smallest size into which these boxes can be packed. 
Boxes cannot be rotated.
*/

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int

int predicate(ll side, ll w, ll h, ll n){
     ll lengthByWidth = (side/w);
     ll lengthByHeight = (side/h);
     if(lengthByWidth > 1e9 || lengthByHeight > 1e9) return 1;
     else return (lengthByWidth * lengthByHeight) >= n;
}

ll valueOfR(){
  ll r = 1;
  while(predicate(r, 1e9, 1e9, 1e9) != 1) {
          r *= 2;
         // cout<<"r = "<<r<<endl;
  }
  return r;
}

signed main(){
          eff;
          int t;
          cin>>t;
          while(t--){
            ll w, h, n;
            cin>>w>>h>>n;

            ll L = 1, R = valueOfR(); // 4 * 1e13;
            //for(int i = 1; i < 150; i++){
           while(L + 1 < R){
               ll M = L + (R - L)/2;
               if(predicate(M, w, h, n) == 0) L = M;
               else R = M;
            }
            cout<<R<<endl;
          }
          return 0;
}

// int main(){
//           cout<<valueOfR()<<endl;
//           return 0;
// }

// 35184372088832
