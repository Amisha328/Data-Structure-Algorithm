// Check if a number is a power of two
// Problem link:
// https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1?


#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        return n > 0 && ((n & (n-1)) == 0);
        
    }
};

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        long long n;
        cin>>n;

        Solution ob;
         if(ob.isPowerofTwo(n))//Now, if log2 produces an integer not decimal then we are sure raising 2 to this value
             cout<<"YES"<<endl;
         else
            cout<<"NO"<<endl;
    }
    return 0;
}
