// Floyd Warshall 
// Problem link:
// https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1#
// https://www.codingninjas.com/codestudio/problem-details/flloyd-warshall_2041979
// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

#include<bits/stdc++.h>
using namespace std;

// TC-> O(n^3) || SC -> O(1)
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&dist){
	    int v = dist.size();
	    
	    for(int k = 0; k < v; k++){
	        for(int i = 0; i < v; i++){
	            for(int j = 0; j < v; j++){
	                if(i == k || j == k || dist[i][k] == -1 || dist[k][j] == -1) 
	                    continue;
	                else if(dist[i][j] == -1)
	                    dist[i][j] = INT_MAX;
	               
	                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	            }
	        }
	    }

	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
} 