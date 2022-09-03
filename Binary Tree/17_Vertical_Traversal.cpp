// Vertical Traversal of Binary Tree 
// https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1#
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

struct Node
{
    int data;
    Node *left, *right;

    Node(int k)
    {
        data = k;
        left = right = NULL;
    }
};
// LEETCODE 
vector<vector<int>> verticalTraversal(Node* root) 
{
        queue<pair<Node*, pair<int,int>>> todo;  // node,{vertical, level}
        // we have used multiset because there can be nodes with same value in the same vertical line
        // and also we have to sort these nodes by their values.
        map<int, map<int, multiset<int>>> mp; // vectical -> {level -> node data}
        todo.push({root, {0, 0}});
        while(!todo.empty())
        {
            auto p = todo.front();
            todo.pop();
            Node *node = p.first;
            int vert = p.second.first;
            int level = p.second.second;
            mp[vert][level].insert(node->data);
            if(node->left)
                todo.push({node->left, {vert-1, level+1}});
            if(node->right)
                todo.push({node->right, {vert+1, level+1}});
        }
        
        vector<vector<int>> ans;
        // For every vertical store all the multiset node values at each level.
        for(auto p: mp) // {vertical}
        {
            vector<int> temp;
            for(auto q : p.second)  // {level, multiset}
                // vector_name.insert(position, iterator1, iterator2)
                // position – It specifies the position at which insertion is to be done in vector.
                // iterator1 – It specifies the starting position from which the elements are to be inserted
                // iterator2 – It specifies the ending position till which elements are to be inserted
                    temp.insert(temp.end(), q.second.begin(), q.second.end());
            ans.push_back(temp);
        }
        return ans;
}

signed main(){
    eff;
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);
    vector<vector<int>> vertical_elements;
    vertical_elements = verticalTraversal(root);
    for(auto x : vertical_elements)
    {
          for(auto y: x)
                    cout<<y<<" ";
          cout<<endl;
    }

    return 0;
}