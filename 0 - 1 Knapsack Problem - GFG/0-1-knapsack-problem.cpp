//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int findans( int w, int n, int wt[], int val[], int i, vector<vector<int>>&dp )
    {
        if ( w == 0 || i == n ) return 0 ;
        int pick = 0 ;
        
        
        if (dp[w][i] != -1) return dp[w][i] ;
        if ( w-wt[i] >= 0 )
        {
            pick = val[i] + findans( w-wt[i] , n , wt, val, i+1, dp ) ;
        }
        int skip = findans( w, n, wt, val, i+1, dp ) ;
        
        return dp[w][i] = max(pick,skip) ;
    }
    
    
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>>dp( W+1, vector<int>(n+1,-1) ) ;
       return findans( W, n, wt, val, 0, dp ) ;
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