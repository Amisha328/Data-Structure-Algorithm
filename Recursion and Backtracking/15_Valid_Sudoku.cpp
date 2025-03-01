// Valid Sudoku
// Problem link:
// https://leetcode.com/problems/valid-sudoku/
// https://www.codingninjas.com/codestudio/problem-details/sudoku_758961
// https://practice.geeksforgeeks.org/problems/is-sudoku-valid4820/1

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        set<int> row[9], col[9], subgrid[9];
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(mat[i][j] != 0)
                {
                    int val = mat[i][j];
                    
                    if(row[i].count(val)) return 0;
                    else row[i].insert(val);
                    
                    if(col[j].count(val)) return 0;
                    else col[j].insert(val);
                    
                    int index = (3*(i/3) + (j/3));
                    if(subgrid[index].count(val)) return 0;
                    else subgrid[index].insert(val);
                }
            }
        }
        return true;
    }
};