// Aggressive Cows
/*
You are given an array ‘arr’ of size ‘n’ which denotes the position of stalls.
You are also given an integer ‘k’ which denotes the number of aggressive cows.
You are given the task of assigning stalls to ‘k’ cows such that the minimum distance between any two of them is the maximum possible.
Find the maximum possible minimum distance.
*/

/*
Step 1:

x - axis -> distance
y -axis -> free variable -> cows

Graph - montonically decreasing

Step 2: Cutoff point - k

maximum possible minimum distance -> last occurnace
*/

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int predicate(vector<int> &stalls, int dist, int cows){
    int n = stalls.size();
    int cntCows = 1; //no. of cows placed
    int lastPos = stalls[0]; //position of last placed cow.
    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= dist) {
            cntCows++; //place next cow.
            lastPos = stalls[i]; //update the last location.
        } 
    }
    if (cntCows >= cows) return 0;
    return 1;
}
int aggressiveCows(vector<int> &stalls, int k)
{ 
   int n = stalls.size();
   sort(stalls.begin(), stalls.end());
   int L = 0, R = stalls[n-1]-stalls[0] + 5;
   while(L + 1 < R){
       int M = L + (R - L)/2;
       if(predicate(stalls, M, k) == 0) L = M;
       else R = M;
   }
   return L;
}