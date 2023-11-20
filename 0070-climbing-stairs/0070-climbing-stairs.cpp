class Solution {
public:
    
//     int findAns( int currStairs, int n, vector<int>&dp )
//     {
//         if ( currStairs == n )  return 1 ;
//         if ( currStairs > n )   return 0 ;
        
//         if ( dp[currStairs] != -1 )  return dp[currStairs] ;
        
//         int oneStep = findAns( currStairs + 1, n, dp ) ;
//         int twoStep = findAns( currStairs + 2, n, dp ) ;
        
//         dp[currStairs] = oneStep + twoStep ;
//         return oneStep + twoStep ;
        
//     }
    
    int climbStairs(int n) 
    {
        vector<int>dp(n+1,-1) ;
        dp[1] = 1 ;
        dp[0] = 1 ;
        
        
        //return findAns(0, n, dp ) ;
        
        
        for ( int i = 2 ; i <= n ; i++ )
        {
            dp[i] = dp[i-1] + dp[i-2] ;
        }
        return dp[n] ;
    }
};