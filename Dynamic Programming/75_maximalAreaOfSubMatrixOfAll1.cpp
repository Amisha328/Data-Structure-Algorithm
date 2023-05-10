// Maximum Size Rectangle Sub-matrix With All 1's

#include <bits/stdc++.h>
using namespace std;

int largestHistogramArea(vector<int> &heights){
	int n = heights.size();
	int maxArea = 0;
	stack<int> s;
	for(int i = 0; i <= n; i++){
		while(!s.empty() && (i == n || heights[s.top()] >= heights[i])){
			int height = heights[s.top()];
			s.pop();
			int width;
			if(s.empty())
				width = i;
			else
				width = i - s.top() - 1;
			
			maxArea = max(maxArea, width * height); 
		}
		s.push(i);
	}
	return  maxArea;
}
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
	vector<int> heights(m);
	int maxArea = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(mat[i][j] == 0) heights[j] = 0;
			else heights[j]++;
		}
		int area = largestHistogramArea(heights);
		maxArea = max(maxArea, area);
	}
	return maxArea;
}