// finds the maximum absolute difference between nearest left and right smaller element of every element in array.
// If the element is the leftmost element, nearest smaller element on left side is considered as 0. 
// Similarly if the element is the rightmost elements, smaller element on right side is considered as 0.

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

signed main(){
    eff;
    int n;
    cin>>n;
    vi A(n);
    for(int i=0;i<n;i++)
        cin>>A[i];

      vector<int> ls(n);
      vector<int> rs(n);
     
     
        stack<int> s;
        for(int i = 0; i < n; i++)
        {
            while(!s.empty() && s.top() >= A[i])
                s.pop();
    
            if(s.empty())
                ls[i] = 0;
            else
                ls[i] = s.top();  
    
            s.push(A[i]);          
        }
          
        while(s.size() > 0)
              s.pop();
              
        for(int i = n-1; i >= 0; i--)
        {
            while(!s.empty() && s.top() >=  A[i])
                s.pop();
                
            if(s.empty())
                rs[i] = 0;
            else
                rs[i] = s.top();
                
             s.push(A[i]);      
        }
        // for(int i = 0; i < n; i++)
        //     cout<<ls[i]<<" ";

        // cout<<"\n";

        // for(int i = 0; i < n; i++)
        //     cout<<rs[i]<<" ";

        // cout<<"\n";
        int diff = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            diff = max(diff, abs(ls[i]-rs[i]));
        //    cout<<i<<" "<<abs(ls[i]-rs[i])<<"\n";
        }
        cout<<diff;

    return 0;

}   

