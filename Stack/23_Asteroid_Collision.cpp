// Asteroid Collision
// Problem link:
// https://leetcode.com/problems/asteroid-collision/
// https://www.codingninjas.com/codestudio/problem-details/asteroid-collision_977232

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto x: asteroids)
        {
            // stack is not empty and,
            // current element and top of stack have opposite signs
            while(!st.empty() && x < 0 && st.top() > 0)
            {
                int diff = x + st.top(); 
                // diff is negative then current element value is greater
                // so element on top of stack gets destroyed.
                if(diff < 0)
                    st.pop();
                // diff obtained is +ve then element at the top of the stack is greater
                // current element gets destroyed
                // we set x = 0 to exit from while loop and not add the current element to stack
                else if(diff > 0)
                    x = 0;
                // diff is zero then element at the top of the stack and current element is equal
                // hence both are destroyed hence pop from stack and set curr ele as zero
                else if(diff == 0)
                {
                    x = 0;
                    st.pop();
                }
            }
            // only is x is not destroyed it is added to the stack
            if(x)
                st.push(x);
        }
        vector<int> afterCollision;
        while(!st.empty())
        {
            afterCollision.push_back(st.top());
            st.pop();
        }
        reverse(afterCollision.begin(), afterCollision.end());
        return afterCollision;
    }
};