// Snake and Ladder Problem
// Problem link:
// https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem4816/1#
// https://leetcode.com/problems/snakes-and-ladders/

#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int minThrow(int N, int arr[]){
       vector<int> vis(31, 0);
       vector<int> moves(31,-1);
       for(int i = 0; i < 2*N; i = i+2) 
           moves[arr[i]] = arr[i+1];
       
       queue<pair<int,int>> q;  
       q.push({1,0});
       vis[1] = 1;
       while(!q.empty())
       {
           auto p = q.front();
           q.pop();
           int cell = p.first;
           int turn = p.second;
           if(cell == 30)
                return p.second;
           for(int i = cell+1; i <= cell+6 && i <= 30; i++)
           {
               pair<int,int> pp;
               if(!vis[i])
               {
                   pp.second = turn+1;
                   vis[i] = 1;
                   if(moves[i] != -1)
                        pp.first = moves[i];
                   else
                        pp.first=i;
                   
                   q.push(pp);
               }
           }
       }
   }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}