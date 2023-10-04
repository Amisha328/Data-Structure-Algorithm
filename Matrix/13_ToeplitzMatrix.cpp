// Toeplitz Matrix
/*
A matrix A is said to be toeplitz if every diagonal (of all sizes) 
from the top-left to the bottom-right has the same elements. 
*/


#include <bits/stdc++.h>
using namespace std;

int isToeplitzMatrix(vector<vector<int>> &mat, int n, int m){
  for(int r = 1; r < n; r++){
    for(int c = 1; c < m; c++){
      if(mat[r][c] != mat[r-1][c-1]) return 0;
    }
  }
  return 1;
}
int main() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        cin>>mat[i][j];
      }
    }
    cout<<isToeplitzMatrix(mat, n, m)<<endl;
  return 0;

}