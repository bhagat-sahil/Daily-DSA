class Solution {
public:
    
    int findTribo( int n, vector<int>&dp )
    {
        if ( n == 0 ) return 0 ;
        if ( n <= 2 )   return 1 ;
        
        
        if ( dp[n] != -1 )  return dp[n] ;
        
        return dp[n] = findTribo( n-1, dp ) + findTribo( n-2, dp ) + findTribo( n-3, dp ) ;
        
    }
    
    
    
    int tribonacci(int n) 
    {
        vector<int>dp( n + 1, -1 ) ;
        return findTribo( n, dp ) ;
        
    }
};