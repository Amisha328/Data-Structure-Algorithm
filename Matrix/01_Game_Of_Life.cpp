// Game of Life
// Problem link:
// https://leetcode.com/problems/game-of-life/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Rules:
    // 1 - if 2 or 3 ones else die(0)
    // 0 - gets 1 (alive) if 3 live, else remian dead(0)
    
    // Inutions:
    // Original  | New | Final State
    //     0     |  0  |   0 
    //     1     |  0  |   1
    //     0     |  1  |   2
    //     1     |  1  |   3 
    
    int rows, cols;
    int countNeighbours(vector<vector<int>>& board, int r, int c)
    {
        int neigh = 0;
        // nested loop going from top left neighbour to bottom right neighbour i.e 8 neighbours
        //  |___|___|___|
        //  |___|_r_|___|
        //  |___|___|___|
        for(int i = r-1; i < r+2; i++)
        {
            for(int j = c-1; j < c+2; j++)
            {    // for the original position and out of bound position ignore
                if((i == r && j == c) || (i < 0 || i == rows) || (j < 0 || j == cols))
                    continue;
                //for rest of positions where,
                // value is 1 (i.e original state is alive and new state is dies).
                // value is 3 (i.e original state is alive and new state is alive)
                if(board[i][j] == 1 || board[i][j] == 3)
                    neigh++;
            }
        }
        return neigh;
    }
    void gameOfLife(vector<vector<int>>& board) {
        rows = board.size();
        cols = board[0].size();
      
        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < cols; c++)
            {
                 int neighCount = countNeighbours(board, r, c);
                 if(board[r][c]) // 1
                 {
                     if(neighCount == 2 || neighCount == 3)
                        board[r][c] = 3;
                 }
                 else // 0
                 {
                     if(neighCount == 3)
                         board[r][c] = 2;
                 }
            }
        }
        
        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < cols; c++)
            {
                if(board[r][c] == 1)
                    board[r][c] = 0;
                else if(board[r][c] == 2 || board[r][c] == 3)
                    board[r][c] = 1;
            }
        }
    }
};