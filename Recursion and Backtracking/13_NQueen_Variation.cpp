// Represent such that number in the ith place denotes that the ith-column queen
// which is placed in the row with that number.

// Probelem link:
// https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    void solve(int col, int n, vector<bool> &leftRow, vector<bool> &upperDiagonal, vector<bool> &lowerDiagonal, vector<int> &arr, vector<vector<int>> &res) {

        if(col == leftRow.size()) {
            res.push_back(arr);
            return;
        }
        
        for(int row = 0; row < n; row++) {

            if(!leftRow[row] && !upperDiagonal[row+col] && !lowerDiagonal[leftRow.size()-1+col-row]) {

                leftRow[row] = upperDiagonal[row+col] = lowerDiagonal[col-row+n-1] = true;

                arr.push_back(row+1);

                solve(col+1, n, leftRow, upperDiagonal, lowerDiagonal, arr, res);

                arr.pop_back();

                leftRow[row] = upperDiagonal[row+col] = lowerDiagonal[col-row+n-1] = false;
            }
        }
    }

    vector<vector<int>> nQueen(int n) {

        vector<vector<int>> res;
        vector<int> arr;
        vector<bool> leftRow(n);
        vector<bool> upperDiagonal(2*n-1);
        vector<bool> lowerDiagonal(2*n-1);

        solve(0, n, leftRow, upperDiagonal, lowerDiagonal, arr, res);

        return res;

    }
};