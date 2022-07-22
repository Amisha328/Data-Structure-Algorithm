// Unique rows in boolean matrix
// Problem link:
// https://practice.geeksforgeeks.org/problems/unique-rows-in-boolean-matrix/1

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
        bool insert(int M[MAX][MAX],int row,int col){
            Node *node = root;
            bool flag = false;
            for(int c = 0; c < col; c++){
                int num = M[row][c];
                if(!node->containsKey(num)){
                    node->put(num, new Node());
                    flag = true;
                }
                node = node->get(num);
            }
            return flag;
        }
};
vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
    Trie trie;
    vector<vector<int>> ans(0,vector<int> (col));
    int k = 0;
    for(int i = 0; i < row; i++){
        if(trie.insert(M, i, col)){
            ans.resize(ans.size()+1, vector<int> (col));
            for(int j = 0; j < col; j++){
                ans[k][j] = M[i][j];
            } 
            k++;
        }
    }
    return ans;
}