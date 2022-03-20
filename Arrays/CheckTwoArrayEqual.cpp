// Check if two arrays are equal or not 
// Problem link: https://www.geeksforgeeks.org/check-if-two-arrays-are-equal-or-not/

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

class Solution{
    public:
     /*
    //Function to check if two arrays are equal or not.
    // TC -> O(n) | SC->O(n)
    bool check(vector<ll> A, vector<ll> B, int N) {
        map<ll, ll> mp;
        for(int i = 0; i < N; i++)
            mp[A[i]]++;
            
        for(int i = 0; i < N; i++)
        {
            if(mp.find(B[i]) == mp.end())
                return false;
            
            //If an element of B[] appears more
            // times than it appears in A[]
            if(mp[B[i]] == 0)
                return false;
                
            mp[B[i]]--;
        }
        return true;
    }*/

    // TC->O(n) | SC->O(1)
    bool check(vector<ll> A, vector<ll> B, int N) {
              // to store xor of both arrays
              int b1 = A[0];
              int b2 = B[0];
              for(int i = 1; i < N; i++)
              {
                        b1 ^= A[i];
                        b2 ^= B[i];
              }
              int ans = b1^b2;
              
              // if xor is zero means they are equal 
              if(ans == 0)
                    return true;
             
             return false;
    }
};

int main()
 {
        int n;
        cin>>n;
        vector<ll> arr(n,0),brr(n,0);
        
        // increase the count of elements in first array
        for(ll i=0;i<n;i++)
            cin >> arr[i];
        
        // iterate through another array
        // and decrement the count of elements
        // in the map in which frequency of elements
        // is stored for first array
        for(ll i=0;i<n;i++)
            cin >> brr[i];
        Solution ob;
        cout << ob.check(arr,brr,n) << "\n";
	return 0;
}