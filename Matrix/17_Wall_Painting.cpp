// Wall Painting Problem

// Problem Statement:
/*
There is huge square wall of size 1000×1000. A point on the wall can be determined by it's coordinate (x,y)
where x,y∈[0,1000] painters come and paint a rectangular portion of the wall such that the endpoints of 
the rectangle are integer coordinates. Each rectangle is given to you in the form x1,y1,x2,y2 where (x1,y1)
is the top left corner coordinates of the rectangle and (x2,y2) is the bottom right corner coordinates.

Your task is to calculate the area of the wall where exactly K painters have painted. The number K is provided to you.
*/

// Intution:
/*
Whneever we have to find the count of intersecting objects (cells/area) we can always think of differnece aray approach.
Cummulative Sum or Prefix Sum
*/

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int main() {
    eff;
    long long N, K;
    cin >> N >> K;

    vector<vector<int>> diffArray(1001, vector<int>(1001, 0));

    for (auto i = 0; i < N; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // it marks the start of the rectangle, indicating that this cell is covered by one more rectangle.
        diffArray[x1][y1]++;
        // it marks the column just after the rectangle ends horizontally. By decrementing this cell,
        // the code indicates that the rectangle no longer covers this column.
        diffArray[x1][y2]--;
        // it marks the row just after the rectangle ends vertically. 
        // Decrementing this cell signifies that the rectangle no longer covers this row.
        diffArray[x2][y1]--;
        // Incrementing this cell indicates that the rectangle has ended, 
        // and this cell is no longer covered by the rectangle.
        diffArray[x2][y2]++;
    }
    // for(int i = 0; i < 10; i++){
    //       for(int j = 0; j < 10; j++){
    //                 cout<<diffArray[i][j]<<" ";
    //       }
    //       cout<<endl;
    // }

    // first row as coordinates can also be in first row as x ∈ [0,1000]
    for(int c = 1; c <= 1000; c++){
        diffArray[0][c] += diffArray[0][c-1];
    }

    // first col as coordinates can also be in first col as y ∈ [0,1000]
    for(int r = 1; r <= 1000; r++){
        diffArray[r][0] += diffArray[r-1][0];
    }

    // calculating Prefix Sum
    for (int i = 1; i <= 1000; ++i) {
        for (int j = 1; j <= 1000; ++j) {
            diffArray[i][j] += diffArray[i - 1][j] + diffArray[i][j - 1] - diffArray[i - 1][j - 1];
        }
    }
  
    // cout<<"After calculating Prefix Sum"<<endl;
    // for(int i = 0; i < 10; i++){
    //       for(int j = 0; j < 10; j++){
    //                 cout<<diffArray[i][j]<<" ";
    //       }
    //       cout<<endl;
    // }
    
    /*
    how is prefix sum determines the area of the intersecting rectangle?

    For each cell where the cumulative/prefix sum equals K, the area is 1 unit.
    The total area where exactly K rectangles intersect is the sum of these individual areas, 
    which is equal to the count of cells where the prefix sum equals K.
    */
    long long totalArea = 0;
    for (int i = 1; i <= 1000; ++i) {
        for (int j = 1; j <= 1000; ++j) {
            if (diffArray[i][j] == K) {
                totalArea++;
            }
        }
    }

    cout << totalArea << endl;

    return 0;
}
