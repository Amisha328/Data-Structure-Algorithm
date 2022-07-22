// Maximum XOR With an Element From Array
// Problem link:
// https://leetcode.com/problems/maximum-xor-with-an-element-from-array/
// https://www.codingninjas.com/codestudio/problems/max-xor-queries_1382020

struct Node{
    Node *links[2];
    
    bool containsKey(int bit){
        return (links[bit] != NULL);
    }
    
    Node *get(int bit){
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
                int bit = (num >> i) & 1;
                if(!node->containsKey(bit)){
                    node->put(bit, new Node());
                }
                node = node->get(bit);
            }
        }
        int getMax(int num){
            Node * node = root;
            int maxVal = 0;
            for(int i = 31; i >= 0; i--){
                int bit = (num >> i) & 1;
                if(node->containsKey(!bit)){
                    maxVal = maxVal | (1 << i);
                    node = node->get(!bit);
                }
                else
                    node = node->get(bit);
            }
            return maxVal;
        }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;
        vector<int> ans(queries.size(), 0);
        vector<pair<int, pair<int, int>>> offlineQueries;
        sort(nums.begin(), nums.end());
        int idx = 0;
        for(auto it: queries){
            offlineQueries.push_back({it[1], {it[0], idx++}});
        }
        // O(QlogQ)
        sort(offlineQueries.begin(), offlineQueries.end());
        int i = 0;
        // O(Q * 32 + N * 32)
        for(auto &it: offlineQueries){
            int ai = it.first;
            int xi = it.second.first;
            int index = it.second.second;
            while(i < nums.size() && nums[i] <= ai){
                trie.insert(nums[i]);
                i++;
            }
            if(i != 0)
                ans[index] = trie.getMax(xi);
            else
                ans[index] = -1;
        }
        return ans; 
    }
};