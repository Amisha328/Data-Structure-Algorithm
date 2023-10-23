// Square Root of N
// Problem Statement:
/*
You are given a number N. You need to print square-root of N.
Important Notes:
1) Do not use built-in libraries.
*/

// TC: O(log(N))
#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// Using the SBA for the last occurance
int predicate(int M, int X){
          // we are using equal for the case like X = 16 which has a exact sqrt as 4.
          if (M * M <= X) return 0;
          else return 1;
}
int main(){
          eff;
          long long N;
          cin>>N;
          if(N == 1){
            cout<<1<<endl;
            return 0;
          }
          int L = 0, R = N;
          while(L + 1 < R){
              int M = L + (R - L)/2;
              if(predicate(M, N) == 0) L = M;
              else R = M;      
          }
          cout<<L<<endl;
          return 0;
}