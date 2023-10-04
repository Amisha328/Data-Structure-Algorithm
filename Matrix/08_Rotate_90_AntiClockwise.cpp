// Rotate Matrix 90 Degree AntiClockwise
// Problem link:
// https://www.codingninjas.com/studio/problems/rotate-matrix-by-90-degrees_981261?leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;

// TC: O(N^2) ASC: O(1)
vector<vector<int>> rotateMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    // Transpose
    for(int i = 0; i < n-1; i++){
        for(int j= i+1; j < n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // swap first row with last row, second with second last and so on...
    for(int i = 0; i < n/2; i++){
        for(int j = 0; j < n; j++){
            swap(matrix[i][j], matrix[n-1-i][j]);
        }
    }
    return matrix;
}