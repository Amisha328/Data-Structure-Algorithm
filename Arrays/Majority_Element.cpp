// Majority Element
// Majority element is an element that appears more than n/2 times in an array of size n. 

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

signed main(){
    eff;
    int n;
    cin>>n;
    vi v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];

    // Using Moore’s Voting Algorithm
    // find the candidate for Majority Element
    int maj_index = 0, count = 1;
    for(int i = 1; i < n; i++)
    {
        if(v[maj_index] == v[i])
            count++;
        else
            count--;    

        if(count == 0)
        {
            maj_index = i;
            count = 1;
        }
    }

    // check if the element at index res is the majority element
    count = 0;
    for(int i = 0; i < n; i++)
    {
        if(v[i] == v[maj_index])
            count++;

    }
    if(count > n/2)
            cout<<v[maj_index]<<endl;
    else
        cout<<-1<<endl;        

    return 0;
}

// Time Complexity: O(n)+O(n) = O(n)
// Auxiliary Space: O(1)