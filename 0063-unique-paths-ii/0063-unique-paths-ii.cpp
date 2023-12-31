class Solution {
public:
    
    int findPaths( int row, int col, int m, int n, vector<vector<int>>&dp, vector<vector<int>>&obstacleGrid )
    {
        if ( row >= m || col >= n ) return 0 ;
        if ( obstacleGrid[row][col] == 1 )  return 0 ;
        if ( row == m-1 && col == n-1 ) return 1 ;
        
        
        if ( dp[row][col] != -1 )   return dp[row][col] ;
        
        int right = findPaths( row, col+1, m, n, dp, obstacleGrid ) ;
        int bottom = findPaths( row+1, col, m, n, dp, obstacleGrid ) ;
        
        return dp[row][col] = right + bottom ;
        
    }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size() ;
        int n = obstacleGrid[0].size() ;
        
        vector<vector<int>>dp(m+1,vector<int>(n+1, -1 )) ;
        return findPaths( 0, 0, m, n, dp, obstacleGrid ) ;
    }
};