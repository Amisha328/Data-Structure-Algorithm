// Check Knight Tour Configuration
// Problem link:
// https://leetcode.com/problems/check-knight-tour-configuration/description/

class Solution {
public:
    vector<pair<int, int>> dir = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
    bool solve(vector<vector<int>> &board, int i, int j, int count, int n){
            if(count == (n*n)) return true;
            //cout<<"count = "<<count<<"\n";
            for(int k = 0; k < 8; k++){
                        int x = i + dir[k].first;
                        int y = j + dir[k].second;
                        //cout<<"x = "<<x<<" y = "<<y<<" count = "<<count<<endl;
                        if(x >= 0 && x < n && y >= 0 && y < n && board[x][y] == count){
                                //cout<<"True\n";
                                if(solve(board, x, y, count+1, n)) return true;
                                else return false;
                        }
            }
            return false;     
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0] != 0) return false;
        return solve(grid, 0, 0, 1, grid.size());
    }
};
