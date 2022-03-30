// Sorting Elements of an Array by Decreasing Frequency
// https://practice.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency/0#

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define vi vector<int>


// // TC->O(nlogn) | SC->O(n)
vector<int> frequencySort(vector<int>& nums) 
{
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        
        // Using Lamba function to sort
        // Lamda: [&] (parameter) { Expression }
        // Take two elements from nums array and compare their frequency in mp
        // if frequency is not equal return element with higher frequency
        // if equal then return the smaller element
        sort(nums.begin(), nums.end(), [&](int a, int b) -> bool {
           return (mp[a] != mp[b]? mp[a] > mp[b] : a < b);
        });
        
        return nums;
}
int main(){
    eff;
    int t;
    cin>>t;
    while(t--){
          int n;
          cin>>n;
          vector<int> arr(n);
          for(int i = 0; i < n; i++)
                    cin>>arr[i];
          arr = frequencySort(arr);
          for(auto x: arr)
              cout<<x<<" ";
          cout<<endl;
    }
    return 0;
}