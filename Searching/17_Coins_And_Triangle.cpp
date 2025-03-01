// https://www.codechef.com/practice/INTBINS01/problems/TRICOIN

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 

int predicate(ll x, ll n){
   if((x*(x+1))/2 <= n) return 0;
   else return 1;
}
int main(){
          eff;
          int t;
          cin>>t;
          while(t--){
                    ll n;
                    cin >> n;
                    // Step 1: Monotonically increasing
                    // Step 2: Cutoff point - n
                    // Step 3: Code:
                    ll L = 0, R = 2 * 1e9;
                    /*
                    Reason for taking R = 2 * 1e9

                    Rule:
                    According to rule of invarient - SBA
                    l should remain in block 0
                    r should remian in block 1
                    then,
                    predicate(l) should always return 0
                    predicate(r) should always return 1
                    
                    N is at max 10^18
                    so, for r*(r+1)/2 = r*r 
                    that is, if r = 10^9  then r*r = 10^18

                    to get the min value of r for which the predicate function will return 1
                    r must be slightly greater than 10^9 -> 2 * 10^9
                    */
                    while(L + 1 < R){
                              ll M = L + (R - L)/2;
                              if(predicate(M, n) == 0) L = M;
                              else R = M;
                    }
                    cout<<L<<endl;
          }
          return 0;
}