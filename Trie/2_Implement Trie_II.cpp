// Implement Trie ll
// Preoblem link:
// https://www.codingninjas.com/codestudio/problem-details/implement-trie_1387095

// Operations:
/*
1) Insert a word.
2) Count words equal to given word.
3) Count words that starts with given prefix.
4) Erase given word.
*/

struct Node{
    Node *links[26];
    int cntEndsWith = 0;
    int cntPrefix = 0;
    
    bool containsKey(char ch){
        return (links[ch-'a'] != NULL);
    }
    
    Node *get(char ch){
        return links[ch-'a'];
    }
    
    void put(char ch, Node *node){
        links[ch-'a'] = node;
    }
    
    void increaseEnd(){
        cntEndsWith++;
    }
    
    void increasePrefix(){
        cntPrefix++;
    }
    
    void decreaseEnd(){
        cntEndsWith--;
    }
    
    void decreasePrefix(){
        cntPrefix--;
    }
    
    int getEnd(){
        return cntEndsWith;
    }
    
    int getPrefix(){
        return cntPrefix;
    }
};
class Trie{

    public:
    Node *root;
    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        Node *node = root;
        for(auto x: word){
            if(!node->containsKey(x)){
                node->put(x, new Node());
            }
           node = node->get(x);
           node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        Node *node = root;
        for(auto x: word){
            if(node->containsKey(x)){
                node = node->get(x);
            }
            else return 0;
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        Node *node = root;
        for(auto x: word){
            if(node->containsKey(x)){
                node = node->get(x);
            }
            else return 0;
        }
        return node->getPrefix();
    }

    void erase(string &word){
        Node *node = root;
        for(auto x: word){
            if(node->containsKey(x)){
                node = node->get(x);
                node->decreasePrefix();
            }
            else return;
        }
       node->decreaseEnd();
    }
};
