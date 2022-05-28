// Circle of strings
// Problem link:
// https://practice.geeksforgeeks.org/problems/circle-of-strings4530/1
// https://www.codingninjas.com/codestudio/problem-details/circle-of-words_1754952

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void dfs(vector<int> adj[], vector<int> &visited, int src){
        visited[src] = 1;
        for(auto it: adj[src]){
            if(!visited[it])
                dfs(adj, visited, it);
        }
    }
    int isCircle(int N, vector<string> A)
    {
        vector<int> adj[26];
        vector<int> in(26, 0);
        vector<int> out(26, 0);
        vector<int> visited(26, 0);
        
        for(int i = 0; i < N; i++){
            int ch1 = A[i].front()-'a';
            int ch2 = A[i].back()-'a';
            adj[ch1].push_back(ch2);
            in[ch1]++;
            out[ch2]++;
        }
        
        for(int i = 0; i < 26; i++)
            if(in[i] != out[i])
                return 0;
        
        int src;
        for(int i = 0; i < 26; i++){
            if(out[i]){
                src = i;
                break;
            }
        }
        
        dfs(adj, visited, src);
        for(int i = 0; i < 26; i++){
            if(out[i] && !visited[i]){
                return 0;
            }
        }
        
        return 1;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}