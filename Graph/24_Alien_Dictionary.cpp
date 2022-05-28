// Alien Dictionary - Topological Sort
// Problem link: 
// https://practice.geeksforgeeks.org/problems/alien-dictionary/1
// https://www.codingninjas.com/codestudio/problem-details/alien-dictionary_630423

#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    
    /*
    void dfs(vector<char> adj[], char u, stack<char> s, vector<bool> &visited)
    {
        visited[u] = true;
        
        for(auto & v : adj[u])
        {
            if(!visited[v])
                dfs(adj, v, s, visited);
        }
        
        s.push(u);
    }
    string  topoglogicalSort(vector<char> adj[], int K)
    {
        stack<char> s;
        
        vector<bool> visited(K, false);
        
        string str ="";
        
        for (int i = 0; i < K; i++)
            if (!visited[i])
                dfs(adj, i, s, visited);
                
                
        while(!s.empty())
        {
            char u = s.top();
            s.pop();
            str += u;
        }
        
        return str;
            
    }
    */
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K+1];
        string ans ="";
        
        for(int i = 0; i < N-1; i++)
        {
            string w1 = dict[i], w2 = dict[i+1];
            for(int j = 0; j < min(w1.size(),w2.size()); j++)
            {
                if(w1[j] != w2[j])
                {
                    adj[w1[j]-'a'].push_back(w2[j]-'a');
                    break;
                }
                    
            }
            
        }
        
        vector<int> indegree(K,0);
           for(int i = 0; i<K; i++){
               for(auto x : adj[i]) indegree[x]++;
           }
        
        //return topoglogicalSort(adj, K);
        
        queue<int> q;
        for(int i = 0; i < K; i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            
            ans += (u + 'a');
            
            for(auto &x : adj[u])
            {
                if(--indegree[x] == 0)
                    q.push(x);
            }
            
            
        }
        
        if(ans.size() == K) return ans;
        
        else
            return "";
        
        
        
    }
};


string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
 