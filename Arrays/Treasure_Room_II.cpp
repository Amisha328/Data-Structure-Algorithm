// Treasure Room - II
/*
You have been exploring the tomb of some long dead person. There is a treasure room here full of vast riches. However, the door to it requires some trickery to unlock. There are N
blocks of varied lengths available to you. The i-th block has length li. There are holders for three blocks, you must place one block on each holder. Only when the sum of lengths of the blocks is equal to the width of the door will the door open. The width of the door is W
So, you should pick three blocks i, j and k such that li+lj+lk=W. Which blocks should you pick?
*/


#include <bits/stdc++.h>
using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, w;
  cin>>n>>w;
  vector<int> lengths(n);
  for(int i = 0; i < n; i++) cin>>lengths[i];
  
// Brute force: Using three loops  
// TC: O(N ^ 3) | ASC: O(1)
/*
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      for(int k = j+1; k < n; k++)
        if(lengths[i] + lengths[j] + lengths[k] == w) {
          cout<<i+1<<" "<<j+1<<" "<<k+1<<endl;
          return 0;
        }
    }
  }

  cout<<-1<<endl;
*/

// Efficient: Using Hashing
// TC: O(N ^ 2) | ASC: O(N)
  map<int, int> mp;  // lengths[i] -> i
  for(int i = 0; i < n; i++){
          mp.clear();
          for(int j = i+1; j < n; j++){
                    if(mp.count(w - (lengths[i] + lengths[j]))){
                              cout<<i+1<<" "<<mp[w-(lengths[i] + lengths[j])]+1<<" "<<j+1<<endl;
                              // for(auto x: mp)
                              // cout<<x.first<<" "<<x.second<<endl;
                              return 0;
                    }
                    mp[lengths[j]] = j;
          }
  }
  cout<<-1<<endl;

  return 0;
}
