// Matrix Serach - Using Binary Serach
// Problem Statement
/*
You are given an N×M matrix A. The matrix does not have any repeated elements. Also the matrix is sorted i.e.
for every column j>0 of any row i, Ai,j > Ai,j−1 and for every row i>0, Ai,0>Ai−1,M−1.
You are also given Q queries. Each query has an integer value. For each query you have to output 
the 0-indexed position of the value in the matrix.
*/

// Solution:

// Observation:
/*
To perform a binary search in a sorted matrix, we have to consider the matrix as 1-D sorted array. 
We need to map the 2D indices to 1D indices and then apply binary search.
*/

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// Using SBA for first occurance of element
int predicate(long long val, long long X){
          if(val < X) return 0;
          else return 1;
}
int main(){
          eff;
          int N, M, Q;
          cin>>N>>M>>Q;
          vector<vector<long long>> matrix(N, vector<long long>(M, 0));
          for(int i = 0; i < N; i++){
                    for(int j = 0; j < M; j++){
                              cin>>matrix[i][j];
                    }
          }

          while(Q--){
                    int X;
                    cin>>X;
                    // Converting 2D to 1D, total number of elements is - (N X M)
                    int L = -1, R = (N * M);
                    while(L + 1 < R){
                              int mid = L + (R - L)/2;
                              // Determine the midVal index in 2D array as mid represents the middle index in 1D array
                              /*
                              # row = mid / numberOfColumns

                              Dividing mid by numberOfColumns gives the quotient, 
                              which represents the full rows before the current position mid in the 1D array.

                              For example, if mid = 5 and numberOfColumns = 3, mid / 3 equals 1. 
                              This means there is 1 full row before the element at position 5.

                              # col = mid % numberOfColumns

                              Taking the remainder of mid divided by numberOfColumns gives the position of mid 
                              within the current row.

                              Example, if mid = 5 then, mid % 3 equals 2. 
                              This means the element at position 5 in the 1D array corresponds to row 1, column 2 
                              in the 2D matrix.
                              
                              */
                              int midVal = matrix[mid/M][mid%M];
                              if(predicate(midVal,X) == 0) L = mid;
                              else R = mid;
                    }
                    cout<<(R/M)<<" "<<(R%M)<<endl;
          }
          return 0;
}

// TC: O(Q * log (N * M))
