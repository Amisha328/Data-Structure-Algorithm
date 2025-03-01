// Closest Refuge
/*
Problem statement:
You are given an integer N. You are also given an array A consisting of N integers.
Find the first natural number that is not present in A. Natural numbers are positive integers.
*/

#include <bits/stdc++.h>
using namespace std;

int findMissingNumber(set<int> &s, int max_val){
   int i = 1;
   while(i <= max_val){
          if(!s.count(i)) return i;
          i++;
   }
   return i;
}
int main() {
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i = 0; i < n; i++) cin>>arr[i];
  set<int> s;
  int max_val = *max_element(arr.begin(), arr.end());
  for(auto x: arr) s.insert(x);
  cout<<findMissingNumber(s, max_val);
  return 0;
}