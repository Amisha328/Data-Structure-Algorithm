// Job Sequencing Problem
// Problem link:
// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
// https://www.codingninjas.com/codestudio/problem-details/job-sequencing-problem_1169460

#include <bits/stdc++.h> 
using namespace std;

// GFG
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool compare(Job a1, Job a2)
    {
        return a1.profit > a2.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
       sort(arr, arr+n, compare);
       int maxi = arr[0].dead;
       for(int i = 1; i < n; i++)
       {
           maxi = max(maxi, arr[i].dead);
       }
       
       vector<int> slot(maxi+1, -1);
       int countJobs = 0, jobProfit = 0;
       for(int i = 0; i < n; i++)
       {
           for(int j = arr[i].dead; j > 0; j--)
           {
               if(slot[j] == -1)
               {
                   slot[j] = i;
                   countJobs++;
                   jobProfit += arr[i].profit;
                   break;
               }
           }
       }
       return {countJobs, jobProfit};
    } 
};


// Coding Ninjas
#include <bits/stdc++.h> 
struct Job 
{ 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
bool compare(Job a, Job b){
    return (a.profit > b.profit);
}
int jobScheduling(vector<vector<int>> &jobs)
{
       int n = jobs.size();
       Job arr[n];
        for(int i = 0; i < n; i++){
            arr[i].dead = jobs[i][0];
            arr[i].profit = jobs[i][1];
        }
       sort(arr, arr+n, compare);
       int maxi = arr[0].dead;
       for(int i = 1; i < n; i++)
       {
           maxi = max(maxi, arr[i].dead);
       }
       vector<int> slot(maxi+1, -1);
       int jobProfit = 0;
       for(int i = 0; i < n; i++)
       {
           for(int j = arr[i].dead; j > 0; j--)
           {
               if(slot[j] == -1)
               {
                   slot[j] = i;
                   jobProfit += arr[i].profit;
                   break;
               }
           }
       }
       return jobProfit;
}
