// Separate Stone
// Problem link:
// https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-110/problems

#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// Main logic
class Solution {
  public:
    int separateStones(int N, int K, vector<int> &arr) {
        int countZero = 0, countOne = 0;
        for(auto x: arr){
            if(x == 0)
                countZero++;// 9
            else if(x == 1)
                countOne++; // 8
        }
        
        int ans = (countZero/K) + (countOne/K);
        if(countZero != 0 && countZero < K || countZero%K != 0) ans++;
        if(countOne != 0 && countOne < K || countOne%K != 0) ans++;
        
        return ans;
    }
};


int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> arr(N);
        Array::input(arr,N);
        
        Solution obj;
        int res = obj.separateStones(N, K, arr);
        
        cout<<res<<endl;
        
    }
}
