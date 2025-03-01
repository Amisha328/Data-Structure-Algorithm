// First Index Last Index
/*
You are given an array of n integers sorted in non-decreasing order. You are also given q queries. 
In each query, you are given a single integer and you need to find the first and last occurence of that 
integer in the given array(considering 0-indexing). 
If the element is not present in the array, output −1−1.
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
int findFirstOccurance(int N, vector<long long> &arr, long long X){
          int L = -1, R = N;
          while( L + 1 < R){
                    int M = L + (R - L)/2;
                    if(predicateFirst(arr[M], X) == 0) L = M;
                    else R = M;
          }
          return R;
}
int findLastOccurance(int N, vector<long long> &arr, long long X){
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
          int N, Q;
          cin >> N >> Q;
          vector<long long> arr(N);
          for(int i = 0; i < N; i++) cin>>arr[i];
          while(Q--){
                    long long X;
                    cin >> X;
                    int first = findFirstOccurance(N, arr, X);
                    int last = findLastOccurance(N, arr, X);
                    // If R (last occurnace position) is at N (imaginary position) then value does not exist.
                    /* 1 2 3 4 4      and X = 5
                       0 0 0 0 0 | 1 
                               L   R      
                    */
                    // Or if the R is somewhere in between but its value is not equal to X then X does not exist.
                    /* 1 2 3 4 4   6 7     and X = 5
                       0 0 0 0 0 | 1 1
                               L   R      
                    */
                    
                    if(first == N || arr[first] != X) cout<<-1<<" "<<-1<<endl;
                    else cout<<first<<" "<<last<<endl;
          }
          
          return 0;
}

// TC: O(2 * Q * logN) && ASC: O(1)
