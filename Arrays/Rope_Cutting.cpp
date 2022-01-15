// You are given N ropes. A cut operation is performed on ropes such that all of them are reduced by the length of the smallest rope. 
// Display the number of ropes left after every cut operation until the length of each rope is zero.

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

vi RopeCutting(int arr[], int n)
{
        // Complete the function
        vector<int> v;
        sort(arr,arr+n);
        int cut = arr[0];
        for(int i = 0; i < n; i++)
        {
            if((arr[i] - cut) > 0)
               v.push_back(n-i);
                
            cut = arr[i];    
        }
        
        return v;
}

signed main(){
    eff;
    int n;
    cin >> n;
    int arr[n];
    for(int arr_i = 0; arr_i < n; arr_i++){
        cin>> arr[arr_i];
    }
    vector<int> result = RopeCutting(arr, n);
    for(int i = 0; i < result.size(); i++){
        cout<< result[i] <<" ";
    }
    return 0;
}