// Shortest Source to Destination Path
// Problem link:
// https://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path3544/1#
// https://leetcode.com/problems/shortest-path-in-binary-matrix/
// https://www.codingninjas.com/codestudio/problem-details/shortest-path-in-a-binary-matrix_699835


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool valid(vector<vector<int>> &arr, int n, int m, vector<vector<bool>> &visited, int r, int c){
          // for out of bound boundary cases, 
          // when cell is already visited, and 
          // if grid value at r,c is a 0 i.e not clear path
          // then return false
        if(r < 0 || r >= n || c < 0 || c >= m || visited[r][c] || arr[r][c] == 0) return false;
        visited[r][c] = true;
        return true;
    }
    int shortestDistance(int n, int m, vector<vector<int>> arr, int X, int Y) {
        // if source and destination cell is 0 then can't be traversed
        if(X >= n || Y >= m || arr[0][0] == 0 || arr[X][Y] == 0) return -1;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<vector<int>> q;
        q.push({0, 0, 0}); // x,y,dis
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            if(u[0] == X && u[1] == Y) return u[2];
            if(valid(arr, n, m, visited, u[0]-1, u[1]))  // up
                q.push({u[0]-1, u[1], u[2]+1});
            if(valid(arr, n, m, visited, u[0]+1, u[1])) // down
                q.push({u[0]+1, u[1], u[2]+1});
            if(valid(arr, n, m, visited, u[0], u[1]-1)) // left
                q.push({u[0], u[1]-1, u[2]+1});
            if(valid(arr, n, m, visited, u[0], u[1]+1)) // right
                q.push({u[0], u[1]+1, u[2]+1});
        }
        return -1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
} 