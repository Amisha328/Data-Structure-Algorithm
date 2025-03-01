/*
You are given a string s consisting of lowercase Latin letters (a−z). The score of a string is defined as the XOR of the frequencies of all the distinct letters in the string. You are required to handle two types of queries: 

1 L R : Answer the score of the substring from L to R.
2 X Y : Update the character at the position X to the Yth letter in the English Alphabet
*/

// Intuition and Approach

/*
We need to handle two types of queries efficiently:

# Query Type 1 (L R): Compute the XOR of character frequencies in a substring.
# Query Type 2 (X Y): Update a character at index X to a new character.

Given that string updates and frequency queries can happen frequently, we need a data structure that supports:

# Efficient updates (point updates).
# Efficient prefix queries (for range queries).

A Fenwick Tree (Binary Indexed Tree, BIT) is a great choice because:

# It supports point updates in O(logN).
# It allows us to compute prefix XOR queries in O(logN).

Key Observations:

# The score is defined as the XOR of frequencies of distinct letters in the substring.
# We can track frequency changes in a Fenwick Tree (BIT).
# Since we need XOR operations, we maintain 26 Fenwick Trees, one for each letter ('a' to 'z').


Fenwick Tree (Binary Indexed Tree) Functions:

1. Update Function
Add +1 when a character appears at an index.
Subtract -1 when a character is removed from that index.

2. Prefix Query Function
Computes the prefix XOR of frequency values.

3. Range Query (L, R)
XOR(L, R) = XOR(1, R) ⊕ XOR(1, L-1), which gives the XOR of character frequencies in the substring.
*/


#include <bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

class FenwickTree{
    private:
        vector<int> BIT; // Binary Indexed Tree
        int size;
    public:
        FenwickTree(int n){
            size = n;
            BIT.assign(n+1, 0); // 1 -based indexing
        }

        // Update: Add 'val' at index 'i' - O(log N).
        void update(int i, int val){
            while(i <= size){
                BIT[i] += val;
                i += (i & (-i)); // Move to the next responsible index -> 2's complemet, & with the original number, then add with the original number
            }
        }

        // Query: Compute the sum of elements from index 1 to i - O(log N).
        int sum(int i){
            int res = 0;
            while(i > 0){
                res += BIT[i];
                i -= (i & (-i)); // Move to the parent node in the BIT
            }
            return res;
        }

        // Range Query: Compute the sum from L to R
        int rangeQuery(int l, int r){
            return sum(r) - sum(l-1);
        }
};
int main(){ 
    eff;
    string s;
    cin >> s;

    int q;
    cin >> q;

    int n = s.size();

    vector<char> input(s.begin(), s.end());

    vector<FenwickTree> fenwickTree(26, FenwickTree(n));

    for(int i = 0; i < n; i++){
        int currIdx = input[i] - 'a';
        fenwickTree[currIdx].update(i+1, 1);
    }

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int l, r;
            cin >> l >> r;

            int xorr = 0;
            for(int i = 0; i < 26; i++){
                int charFreq = fenwickTree[i].rangeQuery(l, r);
                if(charFreq > 0) xorr ^= charFreq;
            }
            cout << xorr << "\n";
        }
        else if(type == 2){
            int idx, newCharIdx;
            cin >> idx >> newCharIdx;
            idx--; newCharIdx--; // convert to 0 based index

            int oldCharIdx = input[idx] - 'a';

            if(oldCharIdx == newCharIdx) continue;

            fenwickTree[oldCharIdx].update(idx+1, -1); // Remove old character
            fenwickTree[newCharIdx].update(idx+1, 1); // Add new character

            // Update the string at the index
            input[idx] = 'a' + newCharIdx;

        }
    }

    return 0;
}
