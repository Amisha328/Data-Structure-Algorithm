// Median of two sorted array
// Problem description:
// Given two sorted arrays, find the median of the two.
//
// Solution:
// The median of two sorted arrays is the middle element of the two arrays.
// So, we can find the median by finding the middle element of the two arrays.
// If the length of the two arrays is odd, the median is the middle element.
// If the length of the two arrays is even, the median is the average of the two middle elements.


#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

// This approach only works when n1 <= n2
double findMedian(vi a1, int n1, vi a2, int n2)
{
    int beg = 0, end = n1;
    while(beg <= end)
    {
        int i1 = (beg+end)/2;
        int i2 = (n1+n2+1)/2 - i1;
        int min1 = (i1 == n1) ? INT_MAX : a1[i1];
        int min2 = (i2 == n2) ? INT_MAX : a2[i2];
        int max1 = (i1 == 0) ? INT_MIN : a1[i1-1];
        int max2 = (i2 == 0) ? INT_MIN : a2[i2-1];

        if((max1 <= min2) && (max2 <= min1))
        {
            if((n1+n2)%2 == 0)
                 return (max(max1,max2)+min(min1,min2))/2.0;
            else
                return (double)max(max1, max2);
        }
        else if(max1 > min2)
               end = i1-1;
        else
                beg = i1+1;
    }
    return 0;
}
signed main(){
    eff;
    int n1,n2;
    cin>>n1>>n2;
    vi a1(n1);
    vi a2(n2);
    for(int i = 0; i < n1; i++)
    cin>>a1[i];
    for(int i = 0; i < n2; i++)
    cin>>a2[i];
    
     if(n1 > n2)
    {
        swap(a1,a2);
        swap(n1,n2);
    }
            
    cout<<findMedian(a1,n1,a2,n2);
    return 0;
}

// Time complexilty: O(log(n1))
// Auxiliary Space complexity: O(1)