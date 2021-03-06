// problem statement:
// You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
// f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.
// f(i, j) = |A[i] - A[j]| + |i - j|

// problem link: https://www.interviewbit.com/problems/maximum-absolute-difference/

/*
Solution:
Intuition : Try to separate the terms of i and j. Separate them using neg sign because then the first one will act as max and second will act a min. Hence will give the max abs diff.
Four cases:

A[i] > A[j] , i > j => f(i, j) = (A[i] - A[j]) + (i-j) = (A[i]+i) - (A[j]+j)
A[i] < A[j] , i < j => f(i, j) = -(A[i] - A[j]) + -(i-j) = -(A[i]+i) + (A[j]+j) = - ( (A[i]+i) - (A[j]+j) )
A[i] > A[j] , i < j => f(i, j) = (A[i] - A[j]) + -(i-j) = (A[i]-i) - (A[j]-j)
A[i] < A[j] , i > j => f(i, j) = -(A[i] - A[j]) + (i-j) = -(A[i]-i) + (A[j]-j) = - ( (A[i]-i) - (A[j]-j) )
We can see that 1 and 2 will give the same ans, 3 and 4 will also give the same ans.
So we will find max and min for them. The maximum diff bn them will give the ans.
*/

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

int maxAbsoluteDifference(vector<int> arr, int n)
{
          int mx1 = INT_MIN, mn1 = INT_MAX, mx2 = INT_MIN, mn2 = INT_MAX;
          for(int i = 0; i < n; i++)
          {
                    mx1 = max(mx1, arr[i]+i);
                    mn1 = min(mn1, arr[i]+i);

                    mx2 = max(mx2, arr[i]-i);
                    mn2 = min(mn2, arr[i]-i);
          }
          return max(mx1-mn1, mx2-mn2);
}
signed main()
{
          eff;
          int n;
          cin>>n;
          vi v(n);
          for(int i = 0; i < n; i++)
          cin>>v[i];
          cout<<maxAbsoluteDifference(v, n);
          return 0;
}

// example:
/*
A=[1, 3, -1]

f(1, 1) = f(2, 2) = f(3, 3) = 0
f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

So, we return 5
*/