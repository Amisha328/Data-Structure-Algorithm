// Implement Stack using Queues
// Problem link:
// https://leetcode.com/problems/implement-stack-using-queues/
// https://www.codingninjas.com/codestudio/problem-details/stack-using-queue_795152


#include <bits/stdc++.h> 

// Using single queue
class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i = 0; i < q.size()-1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if(empty()) return -1;
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        if(empty()) return -1;
        return q.front();
    }
    
    bool empty() {
        return (q.size() == 0);
    }
};


// Using Two queues
class MyStack {
public:
    
    queue<int> q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
        q1.pop();
        
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return x;
    }
    
    int top() {
        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
        q1.pop();
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        q1.push(x);
        return x;
    }
    
    bool empty() {
        return q1.empty();
    }
};
