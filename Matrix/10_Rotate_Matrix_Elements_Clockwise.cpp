// Rotate Matrix elements clockwise:
// Problem link:
// https://www.codingninjas.com/studio/problems/rotate-matrix_981260?topList=striver-sde-sheet-problems&leftPanelTab=0

// TC: O(N * M) || SC -> O(1)
#include <bits/stdc++.h> 
using namespace std;

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int top = 0, left = 0, right = m-1, bottom = n-1;

    while(top < bottom && left < right){
        // traverse the matrix layer by layer

        int prev = mat[top+1][left];
        int curr = 0;
        // top layer (left -> right)
        for(int i = left; i <= right; i++){
           curr = mat[top][i];
           mat[top][i] = prev;
           prev = curr;
        }
        top++;

        // right layer (top -> bottom)
        for(int i = top; i <= bottom; i++){
            curr = mat[i][right];
            mat[i][right] = prev;
            prev = curr;
        }
        right--;

        // bottom layer (right -> left)
        if(top <= bottom) {
            for (int i = right; i >= left; i--){
                curr = mat[bottom][i];
                mat[bottom][i] = prev;
                prev = curr;
            }
            bottom--;
        }

        // left layer (bottom -> top)
        if (left <= right) { // checks if there is any element to proceed with
                             // the next layer or if it is the only layer
            for (int i = bottom; i >= top; i--){
                curr = mat[i][left];
                mat[i][left] = prev;
                prev = curr;
            }
            left++;
        }
    }
}