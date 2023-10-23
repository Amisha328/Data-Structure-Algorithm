// Range Sums
/*
You are presented with N numbers. The ith number is ni. The sphinx now asks you Q questions.
The jth question specifies two integers lj and rj. 
You must answer with the sum of integers in the range [lj,rj]. That is the sum of all ni where lj≤i≤rj.*/

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main(){
          eff;
          int n, q;
          cin>>n;
          vector<int> arr(n);
          for(int i = 0; i < n; i++) cin>>arr[i];
          vector<long long> prefixSum(n);
          prefixSum[0] = arr[0];
          for(int i = 1; i < n; i++) 
              prefixSum[i] = prefixSum[i-1] + arr[i];
          // for(int i = 0; i < n; i++) cout<<prefixSum[i]<<" ";
          // cout<<endl;
          cin>>q;
          while(q--){
              int l, r;
              cin>>l>>r;
          //     cout<<"l = "<<l<<" r = "<<r<<endl;
          //     cout<<prefixSum[r-1]<<" "<<prefixSum[l-1]<<endl;
              if(l-1 > 0)
              cout<<prefixSum[r-1]-prefixSum[l-2]<<endl;
              else 
              cout<<prefixSum[r-1]<<endl;
          }
}