// Unique Binary Search Trees
// problem link:
// https://leetcode.com/problems/unique-binary-search-trees/

// DYNAMIC PROGRAMMING:-
#include<bits/stdc++.h> 
using namespace std; 

// A dynamic programming based function to find nth 
// Catalan number 
int numTrees(int n) {
        vector<int>  catalan(n+1);

	// Initialize first two values in table 
	catalan[0] = catalan[1] = 1; 

	// Fill entries in catalan[] using recursive formula 
	for (int i=2; i<=n; i++) 
	{ 
		catalan[i] = 0; 
		for (int j=0; j<i; j++) 
			catalan[i] += catalan[j] * catalan[i-j-1]; 
	} 

	// Return last entry 
	return catalan[n]; 
} 

// For binomial Coefficient solution:
// https://drive.google.com/file/d/1o12hWeMYODHg9-Oed9Fe9QQ3PbqBq1gA/view
