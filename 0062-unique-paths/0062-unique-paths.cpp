class Solution {
public:
    
    
    
    
    int uniquePaths( int m , int n )
    {
        vector<vector<int>>dp(m+1,vector<int>(n+1, -1 )) ;
        for ( int i = m-1 ; i >= 0 ; i-- )
        {
            for ( int j = n-1 ; j >= 0 ; j-- )
            {
                if ( i == m-1 && j == n-1 ) dp[i][j] = 1 ;
                
                else
                {
                    int right = 0 ;
                    int bottom = 0 ;
                    
                    if ( j < n-1 )    right = dp[i][j+1] ;
                    
                    if ( i < m-1 )    bottom = dp[i+1][j] ; 
                    
                    dp[i][j] = right + bottom ;
                }
                
            }
        }
        return dp[0][0] ;
    }
    
    
    
    
};