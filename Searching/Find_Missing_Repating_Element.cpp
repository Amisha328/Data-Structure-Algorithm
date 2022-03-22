// Find Missing And Repeating
// Problem link: https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1#
// https://www.hackerrank.com/contests/kcertc/challenges/find-the-repeating-and-the-missing/problem


#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
// TC -> O(N) | SC->O(1)
    int *findTwoElement(int *arr, int n) {
        // code here
        long long int len = n;

        long long int S = (len * (len+1) ) /2;
        long long int P = (len * (len +1) *(2*len +1) )/6;
        long long int missingNumber=0, repeating=0;
         
        for(int i=0; i < n; i++){
           S -= (long long int)arr[i];
           P -= (long long int)arr[i]*(long long int)arr[i];
        }
         
        missingNumber = (S + P/S)/2;
    
        repeating = missingNumber - S;
    
        int *ans;
    
        ans[0] = repeating;
        ans[1] = missingNumber;
        
        return ans;
    }
};

int main() {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    return 0;
}  