#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 

// we need to find the first position of current char of target in source string after prevIndex 
int predicate(int mid, int prev){
          if(mid <= prev) return 0;
          else return 1;
}

int upperBound(vector<int> &a, int prevIndex){
          int L = -1, R = a.size();
          while(L + 1 < R){
                    int M = L + (R - L)/2;
                    if(predicate(a[M], prevIndex) == 0) L = M;
                    //if(a[M] <= prevIndex) L = M;
                    else R = M;
          }
          if(R == a.size()) return -1;
          else return a[R];
}
int main(){
          eff;
          int t;
          cin>>t;
          while(t--){
                    string T, S;
                    cin>>T>>S;
                    
                    vector<vector<int>> arr(26); // stores the source char -> index position
                    

                    for(int i = 0; i < S.size(); i++)
                              arr[S[i] - 'A'].push_back(i);
                    
                    // for(int i = 0; i <= 26; i++){
                    //       for(auto x: arr[i]){
                    //           cout<<"i = "<<i<<" => x = "<<x<<endl;
                    //       }
                    // }
                    
                    int prevPos = -1, countScan = 1;
                    for(int j = 0; j < T.size(); j++){
                        // this means element of target is not present in source, hence conversion not possible
                        if(arr[T[j] - 'A'].size() == 0){
                              countScan = -1;
                              break;
                        }
                        prevPos = upperBound(arr[T[j] - 'A'], prevPos);
                        if(prevPos == -1){
                              countScan++;
                              j--; // beacause after taking a new scan we need to consider the current chr in new scan
                        }
                    }
                    cout<<countScan<<endl;
          }
          return 0;
}





          


          

          /*
          map<char, int> mp;
          for(int i = 0; i < S.size(); i++) mp[S[i]] = i;

          int noOfScans = 1;
          for(int i = 1; i < T.size(); i++){
                    if(mp.count(T[i]) == 0){
                              cout<<-1<<endl;
                              return 0;
                    }
                    else if(mp[T[i-1]] > mp[T[i]]) noOfScans++;
          }

          cout<<noOfScans<<endl;
          }
          */
