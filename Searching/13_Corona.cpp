// Corona
/*
Corona has affected the country of IslandLand and people need to practice social distancing. 
IslandLand is a country on the X-Axis with M islands floating on water. 
There are N people living in this country. You have been given the start and end coordinates Li and Ri of all the M islands. 
Suppose the government arranges the people in IslandLand in such a way that all the people have their feet on some island segment.
Your task is to find the largest possible value of the minimum distance between any two people and report it to the government so that the government can ensure social distancing.

Important Notes

⦿ People can stand only on integer coordinates.

⦿ Distance between two people standing on different islands has to also be considered.

⦿ It is guaranteed that the islands are non-overlapping

INPUT
The first line contains two integers N and M. The next M lines contain two integers Li, Ri denoting the start point and the end point of the island segment.

OUTPUT
Output a single integer indicating the largest possible value of the minimum distance between any two people
*/

// TC: O(log (maxvalue of array - minvalue of array)) + O(predicate()) =  O(log(1e18)) + O(M) 

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int

int predicate(ll maxDistance, vector<pair<ll,ll>> &islands, ll people){
        ll noOfPeople = 0, prevPos = LONG_MIN;
        
        for(int i = 0; i < islands.size(); i++){
          ll Si = max(prevPos + maxDistance, islands[i].first);
          if(islands[i].second >= Si){
            ll Pi = ((islands[i].second - Si)/maxDistance) + 1;
            noOfPeople += Pi;
            prevPos = Si + (Pi-1)*maxDistance;
          }
        }
        // Determine the last value 
        if(noOfPeople >= people) return 0;
        else return 1;
      
}
int main(){
          eff;
          ll N, M;
          cin>>N>>M;

          vector<pair<ll, ll>> islands;
          for(int i = 0; i < M; i++){
             ll l, r;
             cin>>l>>r;
            islands.push_back({l, r});
          }
          sort(islands.begin(), islands.end());

         
          ll L = 0, R = 1e18+1; // or islands[M-1].second - islands[0].first + 1;  //islands[len-1] - islands[0];
     
          while(L + 1 < R){
             ll mid = L + (R - L)/2;
             if(predicate(mid, islands, N) == 0) L = mid;
             else R = mid;
          }
          // max in min -> last occurnace
          cout<<L<<endl;
          return 0;
}