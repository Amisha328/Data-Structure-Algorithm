// Bit Masking to implement Set Data Structure

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long mask = 0L;
    void insert(int x){
          mask = mask | (1 << x);
          // cout<<"Insert mask "<<mask<<endl;
    }
    void remove(int x){
          mask = mask & ~(1 << x);
          // cout<<"Remove mask "<<mask<<endl;
    }
    void print(){
          for(int bits = 0; bits <= 32; bits++){
                    if(mask & (1 << bits))
                              cout<<bits<<" ";
          }
          cout<<endl;
    }
};

int main(){
    	Solution ob;
    	ob.insert(5);
          ob.insert(1);
          ob.insert(5);
          ob.insert(3);
          ob.remove(5);
          ob.print();
	return 0;
}