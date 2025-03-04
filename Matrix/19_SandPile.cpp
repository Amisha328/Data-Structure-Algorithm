// Problem statement: -- Asked in apple OA

/*

The sandpile(pile, n) function adds n grains of sand to the sand pile in an two -dimentional array of integers, both dimenstions are equal and are always an odd number.

n is how many times a grain of sand falls into the center cell of pile. 

Whenever the number of grains in a cell reaches 4, the sand spreads to each of the 4 neighboring cells. This means the number of grains goes down to zero in the center cell and each neighbor receives 1 grain. 

If the box does not have 4 neighbors, it still loses all its sand (garins are lost when they go beyond the borders). 

Initial state:

0   1   0
0   2   3
1   0   1

grain # 1
0   1   0
0   3   3
1   0   1

grain # 2
0   1   0
0   4   3
1   0   1

toppling
0   2   0
1   0   4
1   1   1

toppling
0   2   1
1   1   0
1   1   2

Grain # 3
0   2   1
1   2   0
1   1   2

Final Grid:
0 2 1 
1 2 0 
1 1 2
*/

// Approach:

/*
Approach
1. Initialize the Grid: You have a 2D array (square matrix) where the dimensions are always odd.
2. Add n Grains: You keep adding grains to the center cell.
3. Toppling Mechanism:
    (a) When a cell has 4 or more grains, it distributes 1 grain to each of its 4 neighbors.
    (b) If the neighboring cells are at the border, grains are lost.
    (c) This continues until all cells have less than 4 grains.
4. Count the Center Falls: Track how many times grains are added to the center.
*/

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int sandPile(vector<vector<int>> &pile, int n){
    int size = pile.size();
    int center = floor(size/2);
    int centerFall = 0;

     // Add n grains to the center cell
    for(int i = 1; i <= n; i++){
        pile[center][center]++;
        centerFall++;

        // Perform toppling until all cells have < 4 grains
        while(true){
            vector<pair<int, int>> changes;

            for(int r = 0; r < size; r++){
                for(int c = 0; c < size; c++){
                    if(pile[r][c] >= 4){
                        changes.push_back({r,c});
                    }
                }
            }

            if(changes.size() == 0) break; //Stop when no more toppling is needed

            // Process all toppling cells
            for(auto &it: changes){
                int r = it.first;
                int c = it.second;
                pile[r][c] -= 4;

                // Distribute grains to neighbors (if within bounds)
                if(r > 0) pile[r-1][c]++;
                if(r < size-1) pile[r+1][c]++;
                if(c > 0) pile[r][c-1]++;
                if(c < size-1) pile[r][c+1]++;
            }
        }
    }
    return centerFall;
}
int main()
{
    eff;
    int size;
    cin >> size;
    vector<vector<int>> pile(size, vector<int>(size));
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cin >> pile[i][j];
        }
    }
    int n;
    cin >> n;
    cout << sandPile(pile, n) << endl;
    cout << "Final Pile\n";
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << pile[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}