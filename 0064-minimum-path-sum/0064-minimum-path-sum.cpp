class Solution {
public:
    
    int findPathSum( int row, int col, int m, int n, vector<vector<int>>&grid, vector<vector<int>>&dp )
    {
        if ( row >= m || col >= n ) return 1e9 ;
        if ( row == m-1 && col == n-1 ) return grid[m-1][n-1] ;
        
        if ( dp[row][col] != -1 ) return dp[row][col] ;
        int right = grid[row][col] + findPathSum( row, col+1, m, n, grid, dp ) ;
        int bottom = grid[row][col] + findPathSum( row+1, col, m, n, grid, dp ) ;
        
        return dp[row][col] = min( right, bottom ) ;
    }
    
    
    
    
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size() ;
        int n = grid[0].size() ;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1)) ;
        return findPathSum( 0, 0, m, n, grid, dp ) ;
    }
};