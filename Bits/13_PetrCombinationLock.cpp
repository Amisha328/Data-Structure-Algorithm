// Petr and a Combination Lock
// Problem link:
// https://codeforces.com/problemset/problem/1097/B

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define vi vector<int>

string solve(vector<int> &arr){
    int n = arr.size();
    for(int num = 0; num < (1 << n); num++){
        int sum = 0;
        for(int bits = 0; bits < n; bits++){
            if(num & (1 << bits))
                sum += arr[bits];
            else
                sum -= arr[bits];
        }
        if(sum % 360 == 0){
            return "YES";
        }
    }
    return "NO";
}

signed main(){
          eff;
          int n;
          cin>>n;
          vector<int> arr(n);
          for(int i = 0; i < n; i++)\
            cin>>arr[i];
          
          cout<<solve(arr)<<endl;
          return 0;
}