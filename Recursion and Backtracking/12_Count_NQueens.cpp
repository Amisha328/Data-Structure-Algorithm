// Count distinct solutions to the n-queens puzzle.
// Problem link:
// https://leetcode.com/problems/n-queens-ii/

/* Note:
    First it check there are no other queen in row the queen is filled.
    As we are putting queen column wise so no need to check for column.
    Then there are two diagonals to check for.

    COLUMN_WISE FILLING = Only left part of the diagonals are checked as positions to the right of the present column are still unfilled.
    ROW_WISE FILLING = Only upper part of the diagonals are checked as positions below of the present column are still unfilled.
    
    If conditions satisfied, Queen is placed and we move to next column.
    If no queen satisfy the problem, we backtrack and try to change the position of previous queen.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void backtrack(int r, int n, int &res, vector<bool> &col, vector<bool> &mainDiag, vector<bool> &antiDiag)
    {
        if(r == n)
        {
            res++;
            return;
        }
        
        for(int c = 0; c < n; c++)
        {
            if(col[c] && mainDiag[r-c+col.size()-1] && antiDiag[r+c])
            {
                col[c] =  mainDiag[r-c+n-1] = antiDiag[r+c] = false;
                backtrack(r+1, n, res, col, mainDiag, antiDiag);
                col[c] =  mainDiag[r-c+n-1] = antiDiag[r+c] = true;
            }
        }
    }
    int totalNQueens(int n) {
        if(n == 1) return 1;
        vector<bool> col(n, true);
        vector<bool> mainDiag(2*(n-1), true);
        vector<bool> antiDiag(2*(n-1), true);
        int res = 0;
        backtrack(0, n, res, col, mainDiag, antiDiag);
        return res;
    }
};

    