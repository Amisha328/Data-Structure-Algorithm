// Number of Matching Subsequences
// Problem link:
// https://leetcode.com/problems/number-of-matching-subsequences/

struct Node {
    Node *links[26];  
    int count = 0;
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL); 
    }
    Node* get(char ch) {
        return links[ch-'a']; 
    }
    void put(char ch, Node* node) {
        links[ch-'a'] = node; 
    }
};

class Solution {
private:
    Node *root = new Node();
public:
    void insert(string word) {
        Node *node = root;
        for(int i = 0; i < word.size();i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node()); 
            }
            node = node->get(word[i]); 
        }
        (node->count)++; 
    }
    
    int dfs(string& s, int i, Node* node) {
        int ans = node->count;
        if (i >= s.length())
          return ans;

        for (int j = 0; j < 26; ++j)
          if (node->containsKey(j + 'a')) {
             int index = s.find('a' + j, i);
             //cout<<"index="<<index<<endl;
             if (index != -1)
               ans += dfs(s, index + 1, node->get(j + 'a'));
          }
          return ans;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        for (auto &word : words)
              insert(word);

        return dfs(s, 0, root);
    }
       
};