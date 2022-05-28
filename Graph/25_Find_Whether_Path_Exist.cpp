// Find whether path exist
// Problem link:
// https://practice.geeksforgeeks.org/problems/find-whether-path-exist5238/1#

#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    // Using DFS
    void solve(vector<vector<int>>& grid, int n, int m, vector<vector<bool>> &visited, int r, int c){
        // for out of bound boundary cases, 
        // when cell is already visited, and 
        // if grid value at r,c is a wall
        // then return
        if(r < 0 || r >= n || c < 0 || c >= m || visited[r][c] || grid[r][c] == 0)
            return;
        
        visited[r][c] = true;
        solve(grid, n, m, visited, r-1, c); // up
        solve(grid, n, m, visited, r+1, c); // down
        solve(grid, n, m, visited, r, c-1); // left
        solve(grid, n, m, visited, r, c+1); // right
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n = grid.size();
        int m = grid[0].size();
        int sr, sc, dr, dc;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) // source
                {
                    sr = i, sc = j;
                }
                else if(grid[i][j] == 2) // destination
                {
                    dr = i, dc = j;
                }
            }
        }
        
        solve(grid, n, m, visited, sr, sc);
        return visited[dr][dc]; // return of destination cell is visited
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
} 