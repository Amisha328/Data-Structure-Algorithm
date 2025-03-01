// Maximal Area Rectangle in Binary Matrix
// Problem link:
// https://leetcode.com/problems/maximal-rectangle/
// https://practice.geeksforgeeks.org/problems/max-rectangle/1#
// https://www.codingninjas.com/codestudio/problem-details/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


class Solution{
  public:
    /*
    // Approach: 1
    // Using two stack
    // TC-> O(N) || SC-> O(N)
  int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftSmaller(n);
        vector<int> rightSmaller(n);
        stack<int> st;
        
        // Finding the Left Smaller 
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            //if no Nearest Smaller to Left exist the take -1(ground)
            if(st.empty())
                leftSmaller[i] = -1;
            else
                leftSmaller[i] = st.top();
            st.push(i);
        }
        
        // empty the stack
        while(!st.empty())
            st.pop();
        
        // Finding the Right Smaller 
        for(int i = n-1; i >= 0; i--)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            
            // if no Next Smaller to Right exist the take n(ground)
            if(st.empty())
                rightSmaller[i] = n;
            else
                rightSmaller[i] = st.top();
            st.push(i);
        }
        
        vector<int> width(n, 0);
        for(int i = 0; i < n; i++)
        {
            width[i] = rightSmaller[i] - leftSmaller[i] - 1;
        }
        
        // calculating the area
        vector<int> area(n, 0);
        for(int i = 0; i < n; i++)
        {
            area[i] = width[i] * heights[i];
        }
        
        int maxArea = 0;
        for(int i = 0; i < n; i++)
        {
            maxArea = max(maxArea, area[i]);
        }
        return maxArea;
    }
    int maxArea(int matrix[MAX][MAX], int n, int m) {
        // Converted 2D matrix to 1D matrix
        vector<int> v(m, 0);
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == 0)
                    v[j] = 0;
                else
                    v[j]++;
            }
            res = max(res, largestRectangleArea(v));
        }
        return res;
    }
    */

    // Approach: 2
    // Using now extra stack
    // TC-> O(N) || SC-> O(1)

        class MinStack {
    public:
        stack<long long int> s;
        long long int minEle;
        MinStack() {
            
        }
        
        void push(int val) {
            if(s.size() == 0)
            {
                s.push(val);
                minEle = val;
            }
            else
            {
                if(val >= minEle)
                    s.push(val);
                else
                {
                    s.push(2L * val - minEle);
                    minEle = val;
                }
            }
        }
        
        int pop() {
            int val;
            if(s.size() == 0)
                return -1;
            else
            {
                if(s.top() >= minEle)
                {
                    val = s.top();
                    s.pop();
                }
                else
                { 
                    val = minEle;
                    minEle = 2L * minEle - s.top();
                    s.pop();
                }
            }
            return val;
        }
        
        int top() {
            if(s.size() == 0)
                return -1;
            else
            {
                if(s.top() >= minEle)
                    return s.top();
                else
                    return minEle;
            }
        }
        
        int getMin() {
            if(s.size() == 0)
                return -1;
            return minEle;
        }
};


int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
