//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapsackUtil(int wt[], int val[], int index, int W, vector<vector<int>>& dp){
        if(index == 0){
            if(wt[0] <= W) return val[0];
            return 0;
        }
        
        if(dp[index][W] != -1) return dp[index][W];
        
        int notTaken = knapsackUtil(wt, val, index-1, W, dp);
        int taken = INT_MIN;
        
        if(wt[index] <= W){
            taken = val[index] + knapsackUtil(wt, val, index-1, W - wt[index], dp);
        }
        
        return dp[index][W] = max(notTaken, taken);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n, vector<int>(W+1, -1));
       return knapsackUtil(wt, val, n-1, W, dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends