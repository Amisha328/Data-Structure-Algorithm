// Direct Binary Search

/*
You are given an array A of N elements which is sorted in increasing order. You have to answer Q queries. 
For each query qi you have to output the 0-indexed position of qi in the given array.

It is guaranteed that there exists exactly one occurrence of every qi in the array.
*/

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// Using the Super templet to find the first occurance of value X.
int predicateFirst(long long val, long long X){
          // All values less than X is 0 for me
          /*                  
                    1 2 | 5 6 8  X = 5
                    0 0   1 1 1
                      L   R -> Here R determines the first pos of value X
          */
          if(val < X) return 0;
          return 1;
}
// Using the Super templet to find the last occurance of value X.
int predicateLast(long long val, long long X){
          // All value less than and equal to X is zero for me
          /*                  
                    1 2 5 | 6 8  X = 5
                    0 0 0   1 1
                        L   R  -> Here L determines the last pos of value X
          */
          if(val <= X) return 0;
          return 1;
}
int main(){
          eff;
          int N, Q;
          cin >> N >> Q;
          vector<long long> arr(N);
          for(int i = 0; i < N; i++) cin>>arr[i];
          while(Q--){
                    long long X;
                    cin >> X;
                    // L  is set to -1 to handle the case of X is at the zeroth index.
                    // R  is set to N to handle the case of X is at the N-1 th index.
                    int L = -1, R = N;
                    while( L + 1 < R){
                      int M = L + (R - L)/2;
                    //   if(predicateFirst(arr[M], X) == 0) L = M;
                    if(predicateLast(arr[M], X) == 0) L = M;
                      else R = M;
                    }
                    // R determines the first index of value X
                    // cout<<R<<endl;

                    // L determines the last index of value X
                    cout<<L<<endl;
          }
          
          return 0;
}

// TC: O(Q * logN) && ASC: O(1)