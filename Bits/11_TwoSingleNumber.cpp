// Two Non Repeating Numbers
// Problem link:
// https://leetcode.com/problems/single-number-iii/description/
// https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1?
// https://www.codingninjas.com/studio/problem-details/unique-pair-using-bits_972997

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int xorr = 0;
        for(auto x: nums){
            xorr ^= x;
        }
        
        // find index of the set bit
        int idx = 0;
        while(xorr){
            if(xorr & 1) break;
            idx++;
            xorr = xorr >> 1;
        }
        
        // perform the xor of individual set
        // group 1 : for number with idx index has bit set
        // group 2 : for numbers with idx index has unset bit
        
        int xor1 = 0, xor2 = 0;
        for(auto x: nums){
            if(x & (1 << idx))
                xor1 ^= x;
            else 
                xor2 ^= x;
        }
        if(xor1 > xor2) return {xor2, xor1};
        else return {xor1, xor2};
    }
};

int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}