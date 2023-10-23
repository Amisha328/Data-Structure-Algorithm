// Empty The Piles
// Problem statement:
/*
There are n piles of stones arranged in row where the i−th pile has ai stones. 
You can perform certain operations on these piles. In one operation, you can select any non-empty pile and remove at most k
stones from it. Your goal to remove all the stones(i.e. empty all the n piles) in at most h operations. Find the minimum value of k
such that you can empty all the piles within h operations.
*/

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int

// Step 1:
/*
n = 4 h = 5
number of stones in each piles: [1  2  3  4]

k determines the min number of stones to be selected in single turn such that you can empty all the piles within h operations.

k = 1 
turn 1:  [ 0 2 3 4 ]
turn 2:  [ 0 1 3 4 ]
turn 3:  [ 0 0 3 4 ]
turn 4:  [ 0 0 2 4 ]
turn 5:  [ 0 0 1 4 ]
turn 6:  [ 0 0 0 4 ]
turn 7:  [ 0 0 0 3 ]
turn 8:  [ 0 0 0 2 ]
turn 9:  [ 0 0 0 1 ]
turn 10:  [ 0 0 0 0 ]

10 operation > h (5) we can't take this.

k = 2
turn 1:  [ 0 2 3 4 ]
turn 2:  [ 0 0 3 4 ]
turn 3:  [ 0 0 1 4 ]
turn 4:  [ 0 0 0 4 ]
turn 5:  [ 0 0 0 2 ]
turn 6:  [ 0 0 0 0 ]

6 operations > h (5) we can't take this

k = 3
turn 1:  [ 0 2 3 4 ]
turn 2:  [ 0 0 3 4 ]
turn 3:  [ 0 0 0 4 ]
turn 4:  [ 0 0 0 1 ]
turn 5:  [ 0 0 0 0 ]

5 == h we can take this.

Observation:

with increase in value of k number of operation is decreasing.

Now, here our answer is the number of operations corresponding to value of k.

Hence, the functions f(k) = numberOfOperations, is montonically decreasing.
*/

// Step 2: cutoff value is h.
// step 3: Code:

int predicate(ll val, vector<ll> &arr, ll &h){
   ll ops = 0, total_ops = 0;
   for(int i = 0; i < arr.size(); i++){
     ops = (ll)ceil((double)arr[i]/(double)val);
    // ops = (ll)(arr[i] + val - 1) / val;
     total_ops += ops;
   }

   // find the min number hence first occurnace logic
   if(total_ops > h) return 0;
   else return 1;
}
int main(){
          eff;
          ll n, h;
          cin>>n>>h;
          vector<ll> arr(n);
          for(int i = 0; i < n; i++) cin>>arr[i];
          ll L = 1, R = *max_element(arr.begin(), arr.end());
          /*
          This loop will work correctly for most cases, but it may fail for some large test cases.
          The problem is that the difference between L and R can become very large, which can cause the loop to take a long time to terminate.
          So we can try to run this loop for fixed number of time:
          TC of Binary search part is O(log(max value in array)) = log(1e9) ~ 30
          So, we can run loop for >= 30 times.
          */
          for(int i = 1; i <= 30; i++){
         // while(L + 1 < R){
                    ll M = L + (R - L)/2;
                    if(predicate(M, arr, h) == 0) L = M;
                    else R = M;
          }
          cout<<R<<endl;
          return 0;
}