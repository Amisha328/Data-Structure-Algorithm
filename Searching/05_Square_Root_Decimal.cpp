// Square Root of N
// Problem Statement:
/*
You are given a number N. You need to print square-root of N.
Important Notes:
1) Do not use built-in libraries.
2) Your code will be accepted if it is atmax 10^-6 error.
*/

// Solution:

/*
 What does atmax 10^-6 error means?
 If your code calculates a floating-point result, it should be accurate to at least six decimal places. 
 If the expected answer is 0.123456 and your code produces 0.123457, the error is within the acceptable 
 range (10^−6) and would likely be accepted. However, if the code produces 0.12345 (which has a larger discrepancy), 
 it might not be accepted if the tolerance level is (10^−6).
*/
 
// Approach 1:
// TC: O(log (N * 10^precision))
#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int predicate(double M, double X){
          if (M * M <= X) return 0;
          else return 1;
}
int main(){
          eff;
          long long N;
          cin>>N;
          double L = 0, R = N;
          double M, E = 1/(pow(10, 6));
          while(L + E < R){
              M = L + (R - L)/2;
              if(predicate(M, N) == 0) L = M;
              else R = M;      
          }
          /*
          If you want to display a floating-point number for a whole number that should always show trailing zeros, 
          you can use 'fixed' in combination with 'setprecision'.
          */
          cout<<fixed<<setprecision(6)<<L<<endl;
          return 0;
}

// Approach 2:
/*

If given 0 <= N <= 10^18
precesion at max is 9.

If complexity of above approach is O(log (N * 10^precision))
then,
log ( 10^18 * 10^9 ) = log(10^27)
now, 2^10 ~ = 10^3 i.e., log(10^3) ~ 10
     log((10^3)^9) = 9 * 10 = 90 steps at max 
     even if take upper bound as 100 or 150 we can still solve the problem
*/

// TC: O(150)
#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int predicate(double M, double X){
          if (M * M <= X) return 0;
          else return 1;
}
int main(){
          eff;
          long long N;
          cin>>N;
          double L = 0, R = N;
          // double M, E = 1/(pow(10, 6));
          int steps = 0;
          while(steps < 150){
              double M = L + (R - L)/2;
              if(predicate(M, N) == 0) L = M;
              else R = M;
              steps++; 
          }
          cout<<fixed<<setprecision(6)<<L<<endl;
          return 0;
}