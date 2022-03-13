// Queries on Number of Points Inside a Circle

// Problem Statement: https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // applying (x-x1)^2 + (y-y1)^2 = r^2
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> arr(queries.size());
        int count = 0;
        for(int i = 0; i < queries.size(); i++)
        {
            int radius = queries[i][2];
            radius = pow(radius , 2);
            for(int j = 0 ; j < points.size() ; j++)
            {
                int x = points[j][0];
                int y = points[j][1];
                int sum = pow(x-queries[i][0], 2) + pow(y-queries[i][1], 2);
                if(sum <= radius)
                    count++;
            }
            arr[i] = count;
            count = 0;
        }
        return arr;
    }
};

int main()
{
  int n;
  cin>>n;
  vector<vector<int>> points(n, vector<int>(2));
  for(int i = 0; i < n; i++)
  {
     for(int j = 0; j < 2; j++)
     {
               cin>>points[i][j];
     }
  }
  int m;
  cin>>m;
  vector<vector<int>> queries(m, vector<int>(3));
  for(int i = 0; i < m; i++)
  {
          for(int j = 0; j < 3; j++)
          {
                    cin>> queries[i][j];
          }
  }
  Solution obj;
  vector<int> ans(m);
  ans = obj.countPoints(points, queries);
  for(int i = 0; i < ans.size(); i++)
          cout<<ans[i]<<" ";
}
