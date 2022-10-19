// Rotate Matrix
// Problem tag: Matrix
// Problem link:
// https://www.codingninjas.com/codestudio/problems/rotate-matrix_981260?topList=striver-sde-sheet-problems&leftPanelTab=0
// Explanation:
// https://www.youtube.com/watch?v=j47QRjqH6Qo

#include <bits/stdc++.h> 
using namespace std;

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int r = 0, c = 0;
    int prev = 0, curr = 0;
    while(r < n && c < m)
    {
        if(r+1 == n || c+1 == m) return;
        prev = mat[r+1][c];
        for(int i = c; i < m; i++)
        {
            curr = mat[r][i];
            mat[r][i] = prev;
            prev= curr;
        }
        r++;
        for(int j = r; j < n; j++)
        {
            curr = mat[j][m-1];
            mat[j][m-1] = prev;
            prev = curr;
        }
        m--;
        if(r < n)
        {
            for(int i = m-1; i >= c; i--)
            {
                curr = mat[n-1][i];
                mat[n-1][i] = prev;
                prev = curr;
            }
        }
        n--;
        if(c < m)
        {
            for(int j = n-1; j >= r; j--)
            {
                curr = mat[j][c];
                mat[j][c] = prev;
                prev = curr;
            }
        }
        c++;
    }
}