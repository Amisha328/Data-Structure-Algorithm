// Maximum XOR of two numbers from two arrays.
// Problem link:
// https://www.codingninjas.com/codestudio/problems/maximum-xor_973113

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
int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
   Trie trie;
    for(auto x: arr1){
        trie.insert(x);
    }
    int max_xor = 0;
    for(int i = 0; i < m; i++){
        max_xor = max(max_xor, trie.findMax(arr2[i]));
    }
    return max_xor;
}
