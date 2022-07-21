// Maximum XOR of two numbers in an array
// Problem link:
// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
// https://practice.geeksforgeeks.org/problems/maximum-xor-of-two-numbers-in-an-array/1

// TC-> O(n * 32)
struct Node{
    Node *links[2];
    
    bool containsKey(int bit){
        return (links[bit] != NULL);
    }
    
    Node * get(int bit){
        return links[bit];
    }
    
    void put(int bit, Node *node){
        links[bit] = node;
    }
};

class Trie{
    private:
        Node *root;
    public:
        Trie(){
            root = new Node();
        }
    
        void insert(int num){
            Node *node = root;
            for(int i = 31; i >= 0; i--){
                int bit = (num >> i) & 1; // if bit is set gives 1 else 0
                if(!node-> containsKey(bit)){
                    node->put(bit, new Node());
                }
                node = node->get(bit);
            }
        }
      int findMax(int num){
          Node *node = root;
          int maxNum = 0;
          for(int i = 31; i >= 0; i--){
              int bit = (num >> i) & 1;
              if(node->containsKey(!bit)){
                  maxNum = maxNum | (1 << i); // turn on the ith bit
                  node = node->get(!bit);
              }
              else
                  node = node->get(bit);
          }
          return maxNum;
      }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto x: nums){
            trie.insert(x);
        }
        int max_xor = 0;
        for(auto x: nums){
            max_xor = max(max_xor, trie.findMax(x));
        }
        return max_xor;
    }
};