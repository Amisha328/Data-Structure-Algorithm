// Set Matrix Zeroes
// Problem link:
// https://leetcode.com/problems/set-matrix-zeroes/
// https://www.codingninjas.com/codestudio/problems/set-matrix-zeros_3846774?topList=striver-sde-sheet-problems&leftPanelTab=0

// Explanation:
// https://leetcode.com/problems/set-matrix-zeroes/discuss/2117948/C%2B%2B-oror-Matrix-oror-Two-approaches-oror-Explanation


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1;
        int row = matrix.size();
        int col = matrix[0].size();
        
        for(int r = 0; r < row; r++)
        {
            if(matrix[r][0] == 0) col0 = 0;
            for(int c = 1; c < col; c++)
            {
                if(matrix[r][c] == 0)
                    matrix[r][0] = matrix[0][c] = 0;
            }
        }
        
        for(int r = row-1; r >= 0; r--)
        {
            for(int c = col-1; c >= 1; c--)
            {
                if(matrix[r][0] == 0 || matrix[0][c] == 0)
                    matrix[r][c] = 0;
            }
            if(col0 == 0) matrix[r][0] = 0;
        }
    }
};