// Rotated Search
// Problem Statement:
/*
A sorted array of length n has been rotated between 0 and n times. 
You are given this array. Find the minimum element in the array. All the elements in the array are distinct.
*/

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 

int predicate(int val, int x){
  if(val > x) return 0;
  else return 1;
}

int main(){
    eff;
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) 
        cin >> arr[i];
    // Step 1: Monotonically increasing
    // Step 2: Cutoff point - last value of the array
    // Step 3: Code:
    int L = -1, R = n;
    while(L + 1 < R){
        int M = L + (R - L) / 2;
        // If mid element is greater than the last element, the minimum element must be in the right half
        if(predicate(arr[M], arr[n - 1]) == 0) 
            L = M;
        // If mid element is less than or equal to the last element, the minimum element must be in the left half
        else 
            R = M;
    }
    // last value
    cout << arr[R] << endl;
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

bool isGreater(double a,int n){
return a*a>=n;
}
int main() {

int n;
cin>>n;
double l=0,r=n,x=1e-6;
while(l+x<r){
double mid=l+(r-l)/2;
if(isGreater(mid,n)==false){
l=mid;
}
else{
r=mid;
}
}
cout<<r<<endl;
return 0;

}
*/
