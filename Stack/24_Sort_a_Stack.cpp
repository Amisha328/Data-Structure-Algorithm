// Sort a Stack
// Problem tag: Stack, Recursion
// Explantion:
// https://rb.gy/dndys7


#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
          int t;
          cin>>t;
          while(t--)
          {
                    SortedStack *ss = new SortedStack();
                    int n;
                    cin>>n;
                    for(int i=0;i<n;i++)
                    {
                    int k;
                    cin>>k;
                    ss->s.push(k);
                    }
                    ss->sort();
                    printStack(ss->s);
          }
}

// TC-> O(n) | SC-> O(1)
void insertNum(stack<int> &s, int x)
{
    if(s.empty() || (!s.empty() && s.top() <= x))
    {
         s.push(x);
         return;
    }
    
    int topEle = s.top();
    s.pop();
    
    insertNum(s, x);
    s.push(topEle);
}
void SortedStack :: sort()
{
  if(s.empty())
        return;
   int num = s.top();
   s.pop();
   
   sort();
   insertNum(s, num);
}