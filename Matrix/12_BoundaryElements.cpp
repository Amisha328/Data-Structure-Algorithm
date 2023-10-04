#include<bits/stdc++.h>
using namespace std;

void printBoundary(vector<vector<int>> &mat, int n, int m)
{
    // top layer
    for (int c = 0; c < m; c++) 
          cout << mat[0][c] << " ";

    // right boundary
    for(int r = 1; r < n; r++)
        cout<< mat[r][m-1]<<" ";

   // bottom layer
    for(int c = m-2; c >= 0; c--)
          cout<<mat[n-1][c]<<" ";

    // left layer
    for(int r = n-2; r >= 1; r--)
          cout<<mat[r][0]<<" ";

}
signed main(){
          int n, m;
          cin>>n>>m;
          vector<vector<int>> mat(n, vector<int>(m, 0));
          for(int i = 0; i < n; i++){
                    for(int j = 0; j < m; j++){
                              cin>>mat[i][j];
                    }
          }
          printBoundary(mat, n, m);
          return 0;
}