// Matrix Search - Using Two Pointers

// TC: O(Q X N X M)
#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main(){
          eff;
          int n, m, q;
          cin>>n>>m>>q;
          vector<vector<long long>> mat(n, vector<long long>(m, 0));
          for(int i = 0; i < n; i++){
                    for(int j = 0; j < m; j++){
                              cin>>mat[i][j];
                    }
          }
         // cout<<"Enter queries"<<endl;
          vector<long long> query(q, 0);
          for(int i = 0; i < q; i++) cin>>query[i];

          int p1 = 0, p2 = m-1;
          int i = 0;
          while(p1 < n && p2 >= 0 && i < q){
                   // cout<<"p1 = "<<p1<<" p2 = "<<p2<<" mat[p1][p2] = "<<mat[p1][p2]<<" query[i] = "<<query[i]<<endl;
                    if(mat[p1][p2] == query[i]){
                              cout<<p1<<" "<<p2<<endl;
                              i++;
                              p1 = 0, p2 = m-1;
                    }
                    else if(mat[p1][p2] < query[i]) p1++;
                    else p2--;
          }
          return 0;
}