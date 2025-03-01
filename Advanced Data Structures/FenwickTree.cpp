/*
Standard Fenwick Tree (Binary Indexed Tree - BIT) implementation, which supports the following two operations:

# Sum Query (prefix sum) → Returns the sum of elements from index 1 to i.
# Update Operation (point update) → Adds a value val to index i.

*/

#include <bits/stdc++.h>
using namespace std;

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
int main() {
    int n, q;
    cin >> n;

    FenwickTree fenwickTree(n);
    vector<int> arr(n+1, 0);

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        fenwickTree.update(i, arr[i]); //  Build the Fenwick Tree
    }

    cin >> q;

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int l, r;
            cin >> l >> r;
            cout << "Sum from " << l << " to " << r << " is: " << fenwickTree.rangeQuery(l, r) << "\n";
        }
        else if(type == 2){
            int idx, val;
            cin >> idx >> val;
            fenwickTree.update(idx, val);
        }
    }
    return 0;
}
