// Serialization is to store a tree in an string so that it can be later restored and,
// Deserialization is reading tree back from the string.
// Problem link:
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// https://www.codingninjas.com/codestudio/problems/serialise-deserialise-a-binary-tree_920328


#include<bits/stdc++.h>
using namespace std;

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

// TC->O(n) | SC->O(n)
string serialize(Node* root) {
        if(!root) return "";
        string s = "";
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node *node = q.front();
            q.pop();
            if(node == NULL)
                s.append("#,");
            else
                s.append(to_string(node->data)+',');
            
            if(node != NULL)
            {
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if(data.size() == 0) return NULL; 
        stringstream s(data);
        string str; 
        getline(s, str, ',');
        Node *root = new Node(stoi(str));
        queue<Node*> q; 
        q.push(root); 
        while(!q.empty()) {
            
            Node *node = q.front(); 
            q.pop(); 
            
            getline(s, str, ',');
            if(str == "#") {
                node->left = NULL; 
            }
            else {
                Node* leftNode = new Node(stoi(str)); 
                node->left = leftNode; 
                q.push(leftNode); 
            }
            
            getline(s, str, ',');
            if(str == "#") {
                node->right = NULL; 
            }
            else {
                Node* rightNode = new Node(stoi(str)); 
                node->right = rightNode;
                q.push(rightNode); 
            }
        }
        return root; 
    }