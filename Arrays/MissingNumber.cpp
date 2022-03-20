// Find the Missing Number
// Problem link: https://www.geeksforgeeks.org/find-the-missing-number/


#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
  /*
    // TC-> O(nlogn) | SC-> O(1)
    int MissingNumber(vector<int>& arr, int n) {
        // Your code goes here
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n; i++)
        {
            if(arr[i] != i+1)
                return i+1;
        }
    }
    */

    // TC-> O(n) | SC-> O(1)
    int MissingNumber(vector<int>& arr, int n) {
        int sum = n*(n+1)/2;
        for(int i = 0; i < n-1; i++)
            sum -= arr[i];
            
        return sum;
    }
};

int main() {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) 
          cin >> array[i];
        Solution obj;
        cout << obj.MissingNumber(array, n) << "\n";
    return 0;
}  