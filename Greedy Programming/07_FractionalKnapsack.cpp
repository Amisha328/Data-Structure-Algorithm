// Fractional Knapsack
// Problem link:
// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
// https://www.codingninjas.com/codestudio/problem-details/fractional-knapsack_975286

#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool compare(Item a, Item b)
    {
            double r1 = (double)a.value/(double)a.weight;
            double r2 = (double)b.value/(double)b.weight;
            return r1>r2;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double profit = 0.0;
        sort(arr, arr+n, compare);
        for(int i = 0; i < n; i++)
        {
            if(W-arr[i].weight >= 0){
                W -= arr[i].weight;
                profit += arr[i].value;
            }
            else
            {
                profit += W * (double)arr[i].value/arr[i].weight;
                break;
            }
        }
        return profit;
    }
};


// { Driver Code Starts.
int main()
{
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i = 0; i < n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
    return 0;
} 