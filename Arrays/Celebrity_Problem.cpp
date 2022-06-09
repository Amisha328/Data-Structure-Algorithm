// Celebrity Problem
// Problem link:
// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1#
// https://www.codingninjas.com/codestudio/problems/the-celebrity-problem_982769?topList=striver-sde-sheet-problems&leftPanelTab=0


#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int c = 0;
        for(int i = 1; i < n; i++){
            // if c knows any i person then it can't be the Celebrity person
            if(M[c][i] == 1)
                c = i;
         }
        for(int i = 0; i < n; i++){
            // i != c is used to avoid person knowing itself condition
            // c knows i or i does not know c
            if(i != c and (M[c][i] == 1 || M[i][c] == 0))
               return -1;
           }
       return c;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
