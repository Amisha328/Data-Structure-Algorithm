#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 

int predicate(vector<int>& arr, int n, int m, ll candies){
    int noOfChildren = 1;
    long long int allocated_candies = 0;
    for(int i = 0; i < n; i++){
        if(allocated_candies + arr[i] <= candies) allocated_candies += arr[i];
        else{
            noOfChildren++;
            allocated_candies = arr[i];
        }
    }
    // if number of children is more than required (m) that means 
    // we need to alloacte more candies to a single person to reduce the number of children required
    // to increase value of mid we move to right hence L = M
    if(noOfChildren > m) return 0;
    else return 1;
}

int main(){
          eff;
          int n,m;
          cin>>n>>m;
          vector<int> arr(n);
          for(int i = 0; i < n; i++)
                    cin>>arr[i];
          if(m > n){
            cout<<-1<<endl;
            return 0;
          }
          ll L = *max_element(arr.begin(), arr.end())-1;
          ll R = accumulate(arr.begin(), arr.end(), 0LL)+1;
          while(L + 1 < R){
                    ll M = L + (R - L)/2;
                    if(predicate(arr, n, m, M) == 0) L = M;
                    else R = M;
          }
          cout<<R<<endl;
}