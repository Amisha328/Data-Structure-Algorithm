// N Queens
// Problem link:
// https://leetcode.com/problems/n-queens/
// https://www.codingninjas.com/codestudio/problem-details/n-queens_759332

#include<bits/stdc++.h>
using namespace std;

// With String - '.'/'Q'
class Solution {
public:
    
    bool safe(vector<string> &sol, int row, int col, int n)
    {
        // left
        for(int i = col; i>=0; i--)
            if(sol[row][i] == 'Q')
                return false;
        
        // left up
        for(int i = row, j = col; i>=0 && j>=0; i--, j--)
            if(sol[i][j] == 'Q')
                return false;
        
        // left down
        for(int i = row, j = col; i<n && j>=0; i++, j--)
            if(sol[i][j] == 'Q')
                return false;
        
        return true;
        
    }
    void Nqueen(vector<vector<string>> &ans, vector<string> &sol,int col, int n)
    {
        // base case to store result
        if(col == n)
        {
            ans.push_back(sol);
            return;
        }
        for(int i = 0; i < n; i++)
        {
            if(safe(sol,i,col,n))
            {
                sol[i][col] = 'Q';
                Nqueen(ans,sol,col+1,n);
                sol[i][col] = '.';
            }
        }
    }
  
    vector<vector<string>> solveNQueens(int n) {
        
        // vcetor to store final result 
        vector<vector<string>> ans;
        
        // vector to store intermediate results
        vector<string> sol;
        
        string s = "";
        for(int i = 0; i < n; i++)
            s+='.';
        
        for(int i = 0; i < n; i++)
            sol.push_back(s);
        
        Nqueen(ans,sol,0,n);
        
        return ans;
        
    }
};


// With Numbers - 0/1
bool isSafe(vector<vector<int>> &sol, int row, int col, int n){
    // left
    for(int i = col; i >= 0; i--){
        if(sol[row][i])
            return false;
    }
    
    // left-upper
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if(sol[i][j]) return false;
    }
    
    // left-down
    for(int i = row, j = col; i < n && j >= 0; i++, j--){
        if(sol[i][j]) return false;
    }
    
    return true;
}
void Nqueen(vector<vector<int>> &ans, vector<vector<int>> &sol, int col, int n){
    if(col == n){
        vector<int> temp;
        for(auto it: sol)
            for(auto x: it)
                temp.push_back(x);
        ans.push_back(temp);
        return;
    }
    for(int i = 0; i < n; i++){
        if(isSafe(sol, i, col, n)){
            sol[i][col] = 1;
            Nqueen(ans,sol,col+1,n);
            sol[i][col] = 0;
        }
    }
}
vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> ans;
    vector<vector<int>> sol(n, vector<int>(n,0));
    Nqueen(ans, sol, 0, n);
    return ans;
}