// Maximum Units on a Truck
/*
You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:

numberOfBoxesi is the number of boxes of type i.
numberOfUnitsPerBoxi is the number of units in each box of the type i.
You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.

Return the maximum total number of units that can be put on the truck.
*/

// Problem link:
// https://leetcode.com/problems/maximum-units-on-a-truck/submissions/

// Variation of Fractional Knapsack

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
         sort(boxTypes.begin(), boxTypes.end(), comp);
         int totalUnits = 0; 
         for(int i = 0; i < boxTypes.size(); i++)
         {
            int boxes = boxTypes[i][0];
            int unitsPer = boxTypes[i][1]; 
            if(truckSize >= boxes)
            {
                truckSize -= boxes;
                totalUnits += boxes * unitsPer;
            }
            else
            {
                totalUnits += (truckSize) * unitsPer;
                break;
            }
        }
        return totalUnits; 
    }

};

int main()
{
	    //size of array and weight
	int n, W;
	cin>>n>>W;	
	vector<vector<int>> boxTypes(n);
          for(int i = 0; i < n; i++)
          {
              cin>>boxTypes[i][0]>>boxTypes[i][1];
          }
          Solution ob;
          cout<<ob.maximumUnits(boxTypes, W)<<endl;
          return 0;
} 
