// Find the Safest Path in a Grid
// Problem link:
// https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(vector<vector<int>>& grid, int n, vector<vector<int>> vis){
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        queue<pair<int, pair<int, int>>> q;

        // store the postions of cell with thief and safety distance as 0.
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    vis[i][j] = 1;
                    q.push({0, {i, j}});
                }
            }
        }

        while(!q.empty()){
            int dis = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            
            grid[r][c] = dis;

            for(int x = 0; x < 4; x++){
                int u = r + dx[x];
                int v = c + dy[x];

                if(u >= 0 && u < n && v >= 0 && v < n && !vis[u][v]){
                    vis[u][v] = 1;
                    q.push({dis+1, {u, v}});
                }
            }
        }
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
         int n = grid.size();
         
         // if the start or end cell has the theif then max safety factor is 0.
         if(grid[0][0] || grid[n-1][n-1]) return 0;

        // Perform the BFS to store the safety distance of each cell from the cell with thief.
        vector<vector<int>> vis(n, vector<int>(n, 0));
        bfs(grid, n, vis);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        // Now determine the maximum safeness factor by using max-heap (priority queue)

        // priority queue stores cells in increasing order of their distance from the nearest thief cell.

        // Performing the Dijkastra Algorithm
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        int safenessFactor = INT_MAX;

        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({grid[0][0], {0, 0}});

        vis[0][0] = 1;

        while(!pq.empty()){
            int dist = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            
            safenessFactor = min(safenessFactor, dist);

            if(r == n-1 && c == n-1) break;

            for(int x = 0; x < 4; x++){
                int u = r + dx[x];
                int v = c + dy[x];

                if(u >= 0 && u < n && v >= 0 && v < n && !vis[u][v]){
                    vis[u][v] = 1;
                    pq.push({grid[u][v], {u, v}});
                }
            }
        }
        return safenessFactor;
    }
};