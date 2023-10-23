// Treasure Room Easy
/*
You have been exploring the tomb of some long dead person. There is a treasure room here full of vast riches. However, the door to it requires some trickery to unlock. 
There are N blocks of varied lengths available to you. The i-th block has length li.
On both sides of the door, you must place one block each. Only when the sum of lengths of the blocks is equal to the width of the door will the door open. The width of the door is W
So, you should pick two blocks i and j such that li+lj=W. Which blocks should you pick?
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

  int n, w;
  cin>>n>>w;
  vector<int> lengths(n);
  for(int i = 0; i < n; i++) cin>>lengths[i];

// Solution 1:
//   for(int i = 0; i < n; i++){
//           for(int j = i+1; j < n; j++){
//                     if(lengths[i] + lengths[j] == w){
//                               cout<<i+1<<" "<<j+1<<endl;
//                               return 0;
//                     } 
                              
//           }
//   }
//   cout<<-1<<endl;

// Solution 2:
/*
vector<pair<int, int>> v;

for(int i = 0; i < n; i++)
  v.push_back({lengths[i], i+1});

sort(v.begin(), v.end());

int p1 = 0, p2 = n-1;
while(p1 < p2){
  if(v[p1].first + v[p2].first == w){
    cout<<v[p1].second<<" "<<v[p2].second<<endl;
    return 0;
  }
  else if(v[p1].first + v[p2].first < w)  
    p1++;
  else p2--;
}
cout<<-1<<endl;
*/

// Solution: 3
  map<int, int> mp;  // lengths[i] -> i
  for(int i = 0; i < n; i++){
          if(mp.count(w - lengths[i])){
                    cout<<mp[w-lengths[i]]+1<<" "<<i+1<<endl;
                    return 0;
          }
          mp[lengths[i]] = i;
  }
  cout<<-1<<endl;
  return 0;

}