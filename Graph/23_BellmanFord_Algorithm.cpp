// Distance from the Source (Bellman-Ford Algorithm) 
// Problem link:
// https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/0/?fbclid=IwAR2_lL0T84DnciLyzMTQuVTMBOi82nTWNLuXjUgahnrtBgkphKiYk6xcyJU#
// https://leetcode.com/problems/network-delay-time/


#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
            // TC-> O(V-1) * O(E) | SC-> O(V)
          vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
                    vector<int> dis(V, 100000000);
                    dis[S] = 0;
                    for(int i = 1; i < V; i++){
                              for(auto it: adj){
                              if(dis[it[0]] + it[2] < dis[it[1]])
                                        dis[it[1]] = dis[it[0]] + it[2];
                              }
                    }

                    // If negative cycle is present
                    int flag = 0;
                    for(auto it: adj){
                              if(dis[it[0]] + it[2] < dis[it[1]]){
                                        flag = 1;
                                        break;
                              }
                    }
                    if(!flag)
                              return dis;
                    else
                              return {};
          }
};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj;
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1;
            t1.push_back(u);
            t1.push_back(v);
            t1.push_back(w);
            adj.push_back(t1);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.bellman_ford(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}
