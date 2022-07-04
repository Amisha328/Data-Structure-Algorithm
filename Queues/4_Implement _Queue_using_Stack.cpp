// Implement Queue Using Stack
// Problem link:
// https://leetcode.com/problems/implement-queue-using-stacks/
// https://www.codingninjas.com/codestudio/problem-details/queue-using-stack_799482
// https://practice.geeksforgeeks.org/problems/queue-using-stack/1/


// TC-> O(1) : push
// TC-> O(1) : amotized for pop and top
// SC-> O(2N)
#include <bits/stdc++.h>
class Queue {
    public:
    stack<int> input, output;
    Queue() {
        
    }
    void enQueue(int val) {
        input.push(val);
    }
    int deQueue() {
        int val = -1;
        if(!output.empty())
        {
            val = output.top();
            output.pop();
        }
        else
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            if(!output.empty())
            {
                val = output.top();
                output.pop();
            }  
        }
        return val;
    }

    int peek() {
        int val = -1;
        if(!output.empty())
            val = output.top();
        else
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            if(!output.empty()) val = output.top();
        }
        return val;
    }

    bool isEmpty() {
       return (input.empty() && output.empty());
    }
};