// Spiral Traversal of a Matrix
// problem link:
// https://www.codingninjas.com/studio/problems/spiral-matrix_840698


#include<bits/stdc++.h>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>>&mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<int> ans;
    int top = 0, left = 0, right = m-1, bottom = n-1;
    while(top <= bottom && left <= right){
        // traverse the matrix layer by layer
        // top layer (left -> right)

        for(int i = left; i <= right; i++)
            ans.push_back(mat[top][i]);
        top++;

        // right layer (top -> bottom)
        for(int i = top; i <= bottom; i++)
            ans.push_back(mat[i][right]);
        right--;

        // bottom layer (right -> left)
        if(top <= bottom) {
            for (int i = right; i >= left; i--)
              ans.push_back(mat[bottom][i]);
            bottom--;
        }

        // left layer (bottom -> top)
        if (left <= right){ // checks if there is any element to proceed with the next layer or if it is the only layer
            for(int i = bottom; i >= top; i--)
                ans.push_back(mat[i][left]);
            left++;
        }
    }
    return ans;
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
          vector<int> ans;
          ans = spiralMatrix(mat);
          for(int i = 0; i < ans.size(); i++) cout<<ans[i]<<" ";
          return 0;
}