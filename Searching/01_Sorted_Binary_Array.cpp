// Super Templet of Binary Search - SBA(Sorted Binary Array) templet

/*
You are given a sorted (in ascending order) binary array (consisting only of 0's and 1's). 
Print the index(0-based) of the first 1 and last 0 in the array. 
If no 0's exist, print -1 instead of the index of the last 0. 
If no 1's exist, print N instead of the index of the first 1.
*/

/*
There are three rules for Super Templet:
1) Search Space [L, R]
2) Navigating the search space
3) Rule of invariant: 
        Block 0    Block 1
       0 0 0 0 0  1 1 1 1 1
L should always     R should always remain
remain in block 0     in block 1
*/
#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main(){
          eff;
          int n;
          cin>>n;
          vector<int> arr(n);
          for(int i = 0; i < n; i++) cin>>arr[i];

          // Consider we want to find the first index pos of 1.

          /*
           We are considering L = -1 and R = N and not L = 0 and R = N-1 to handle the case where 
           0 does not exist (L = -1) -> We consider imaginary pos -1 to have value 0
           1 does not exist (R = N) -> We consider imaginary pos N to have value 1
          */
          int L = -1, R = n;
          int M;
          while(L + 1 < R){
             M = L + (R-L)/2;
             /* 
             if the current value is 0 and we want to find the first index of 1 then,
             we are sure one lies to the right so we discard the elements on left.
             Now, we have two choice 1) take L = M+1 2) take L = M

             now if we do L = M+1 we may voilate the rule 3 of Super templet
             */
             if(arr[M] == 0) L = M;
             /*
             if the current value is 1 and we want to find the first index of 1 then,
             it can either be the current index or any index to the left of it. 
             So we are sure that it will definately not be on the right.
             Now, we have two choice 1) take R = M-1 2) take R = M

             now if we do R = M-1 we may voilate the rule 3 of Super templet and also the current index 
             M can be our first index for 1.
             */
             else R = M;
          }
          cout<<R<<" "<<L<<endl;
          return 0;
}