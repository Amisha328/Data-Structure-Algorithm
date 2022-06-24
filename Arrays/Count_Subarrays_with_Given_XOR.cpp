// Count Subarrays with Given XOR
// Problem link:
// https://www.codingninjas.com/codestudio/problems/1115652?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

/* Idea:
                    xorr
          <--------------------->
          <-----Y----><----X---->
          [  ,   ,   ,  ,  ,  ,  ]

          xorr = Y ^ X
          Y = xorr ^ X
*/

/*
 Input 1:  5 3 8 3 10 | x = 8
 Explantion:
          5  3  8  3  10
          xorr = 0 ^ 5 = 5 != 8
          map => {(5,1)}
          count = 0
          Y = 5 ^ 8 = 13

          xorr = 5 ^ 3 = 6
          map => {(5, 1), (6, 1)}
          count = 0
          Y = 6 ^ 8 = 14

          xorr = 6 ^ 8 = 14
          count = 0
          Y = 14 ^ 8 = 6
          count = map[6] = 1
          map => {(5, 1), (6, 1), (14, 1)}

          xorr = 14 ^ 3 = 13
          count = 1
          Y = 13 ^ 8 = 5
          count += map[5] = 2
          map => {(5, 1), (6, 1), (14, 1), (13, 1)}

          xorr = 13 ^ 10 = 7
          count = 2
          Y = 7 ^ 8 = 15
          map => {(5, 1), (6, 1), (14, 1), (13, 1), (15, 1)}

          return 2
*/

/*

Input 2: 4 2 2 6 4 | x = 6
Explantion:
          xorr = 0 ^ 4 = 4
          count = 0
          Y = 4 ^ 6 = 2
          map => {(4, 1)}

          xorr = 4 ^ 2 = 6
          count = 1
          Y = 6 ^ 6 = 0
          map => {(4,1), (6,1)}

          xorr = 6 ^ 2 = 4
          Y = 4 ^ 6 = 2
          count = 1
          map => {(4,2), (6, 1)}

          xorr = 4 ^ 6 = 2
          Y = 2 ^ 6 = 4
          count = 1 + mp[4] = 1 + 2 = 3
          map => {(4,2)(6,1)(2,1)}

          xorr = 2 ^ 4 = 6
          count = 4
          Y = 6 ^ 6 = 0
          map => {(4, 2), (6, 2), (2, 1)}

          return 4

*/

#include <bits/stdc++.h> 
using namespace std;

int subarraysXor(vector<int> &arr, int x)
{
    int xorr = 0, count = 0;
    map<int, int> mp; // xorr, freq
    for(auto it: arr)
    {
        xorr ^= it;
        if(xorr == x)
            count++;
        if(mp.find(xorr^x) != mp.end())
           count += mp[xorr^x];
        mp[xorr]++;
    }
    return count;
}