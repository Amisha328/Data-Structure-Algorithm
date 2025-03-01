// https://www.codechef.com/practice/INTBINS01/problems/WAV2?tab=statement
/*
Intution:
we don't  r ṇ;;.''/need to calculate the value we just need to find out how many are positive and how many are negative and 0.
*/

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 

// first value that is greater than or equal to value x
int predicate(int mid, int x){
   if(mid < x) return 0;
   else return 1;
}
int main(){
          eff;
          int n, q;
          cin>>n>>q;
          vector<int> arr(n);
          for(int i = 0; i < n; i++) cin>>arr[i];
         
          sort(arr.begin(), arr.end());

          while(q--){
               int x;
               cin>>x;
               ll L = -1, R = n;
               while(L + 1 < R){
                    ll M = L + (R - L)/2;
                    if(predicate(arr[M], x) == 0) L = M;
                    else R = M;
                }
                if(R < n && arr[R] == x) cout<<0<<"\n";
                // if the position of first greater number if even that means there even number of negative numbers
                // e.g x = 80 R = 3 => 4-3 = 1 that means there is just one (odd) value (80-100) that can give a negative value
                // e.g x = 2 R = 1 => 4-1 = 3 that means there are three values (odd) -> (2 - 3) (2 - 5) (2 - 100) hence the final value will be odd
                // (80 - 1) * (80 - 3) * (80 - 5) 
                else if((n-R)%2 == 0) cout<<"POSITIVE\n";
                else cout<<"NEGATIVE\n";
          }
          return 0;
}