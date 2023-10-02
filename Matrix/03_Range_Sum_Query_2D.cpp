// Range Sum Query 2D
// Problem link:
// https://leetcode.com/problems/range-sum-query-2d-immutable/

#include<bits/stdc++.h>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> prefixSumMatrix;
    NumMatrix(vector<vector<int>>& matrix) {
        prefixSumMatrix = vector<vector<int>>(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        for(int i = 0; i < matrix.size(); i++)
        {
            int prefix = 0;
            for(int j = 0; j < matrix[0].size(); j++)
            {
                prefix += matrix[i][j];
                int above = prefixSumMatrix[i][j+1];
                prefixSumMatrix[i+1][j+1] = prefix + above;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++, col1++, row2++, col2++;
        int bottomRight = prefixSumMatrix[row2][col2];
        int above = prefixSumMatrix[row1-1][col2];
        int left = prefixSumMatrix[row2][col1-1];
        int topLeft = prefixSumMatrix[row1-1][col1-1];
        
        return bottomRight - above - left + topLeft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */