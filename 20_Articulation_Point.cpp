// Articulation Point
// problem link: https://practice.geeksforgeeks.org/problems/articulation-point-1/0/

#include<bits/stdc++.h>
using namespace std;


// TC-> O(V+E) | SC-> O(V)
class Solution {
  public:
    void dfs(int node, int parent, vector<int> &tin, vector<int> &low, vector<int> &vis,
             vector<int> adj[], int &timer, vector<int> &isArticulation){
                 vis[node] = 1;
                 tin[node] = low[node] = timer++;
                 int child = 0;
                 for(auto it: adj[node]){
                     if(!vis[it]){
                         dfs(it, node, tin, low, vis, adj, timer, isArticulation);
                         low[node] = min(low[it], low[node]);
                         if(low[it] >= tin[node] && parent != -1)
                            isArticulation[node] = 1;
                        child++;
                     }
                     else
                        low[node] = min(low[node], tin[it]);
                 }
                 
                 if(parent == -1 && child > 1)
                    isArticulation[node] = 1;
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> tin(V, -1);
        vector<int> low(V, -1);
        vector<int> vis(V, 0);
        vector<int> isArticulation(V, 0);
        
        int timer = 0;
        for(int i = 0; i < V; i++){
            if(!vis[i])
                dfs(i, -1, tin, low, vis, adj, timer, isArticulation);
        }
        vector<int> ans;
        for(int i = 0; i < V; i++){
            if(isArticulation[i])
                ans.push_back(i);
        }
        if(ans.size() == 0) ans.push_back(-1);
        return ans;
    }
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends
