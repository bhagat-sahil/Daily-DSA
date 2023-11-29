class Solution {
public:
    
    int findPaths( int row, int col, int m, int n, vector<vector<int>>&dp )
    {
        if ( row >= m || col >= n ) return 0 ;
        if ( row == m-1 && col == n-1 ) return 1 ;
        
        if ( dp[row][col] != -1 )   return dp[row][col] ;
        
        int right = findPaths( row, col+1, m, n, dp ) ;
        int bottom = findPaths( row+1, col, m, n, dp) ;
        
        return dp[row][col] = right + bottom ;
        
    }
    
    
    
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1, -1 )) ;
        return findPaths( 0, 0, m, n, dp ) ;
    }
};