// Largest Number formed from an Array
// problem link: https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1
// https://leetcode.com/problems/largest-number/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

          // GFG Solution
          /*
	static int myCompare(string X, string Y)
	{
	    string XY = X.append(Y);
	    string YX = Y.append(X);
	    return (XY > YX);
	}
	string printLargest(vector<string> &arr) {
	    // code here
	    sort(arr.begin(), arr.end(), myCompare);
	    string ans;
	    for(int i = 0; i < arr.size(); i++)
	        ans.append(arr[i]);
	        
	    return ans;
	    
	}
          */

         // leetcode solution
          static int cmp(int a, int b)
          {
                    string X = to_string(a);
                    string Y = to_string(b);
                    string XY = X.append(Y);
                    string YX = Y.append(X);
                    return (XY > YX);
          }
          string largestNumber(vector<int>& nums) {
                    sort(nums.begin(), nums.end(), cmp);
                    string ans;
                    for(int i = 0; i < nums.size(); i++)
                              ans = ans + to_string(nums[i]);
                    
                    // example [0, 0] o/p -> "0" and not "00"
                    while (ans.length() > 1 && ans[0] == '0')
                    {
                              ans = ans.substr(1);
                    }
                    
                    return ans;
          }
};

int main() {
        int n, i;
        cin >> n;
        //vector<string> arr(n);
        vector<int> nums(n);
//         for (i = 0; i < n; i++) {
//             cin >> arr[i];
//         }
        for (i = 0; i < n; i++) {
            cin >> nums[i];
        }
        Solution ob;
       // auto ans = ob.printLargest(arr);
       auto ans = ob.largestNumber(nums);
        cout << ans << "\n";
    return 0;
} 

