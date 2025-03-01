// Minimum Bit Flips to Convert Number
// Problem link:
// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/
// https://practice.geeksforgeeks.org/problems/bit-difference-1587115620/1?


// TC -> O(log N) | SC -> O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public: 
    int countBitsFlip(int a, int b){
        
       int n = a ^ b;
        int cnt = 0;
        while(n){
            n = n & (n-1);
            cnt++;
        }
        return cnt;
        
    }
};

int main()
{
	int t;
	cin>>t;// input the testcases
	while(t--) //while testcases exist
	{
		int a,b;
		cin>>a>>b; //input a and b

        Solution ob;
		cout<<ob.countBitsFlip(a, b)<<endl;
	}
	return 0;
}
