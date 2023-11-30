class Solution {
public:
    
    int findMinTotal( int row, int col, int m, int n, vector<vector<int>>&triangle, vector<vector<int>>&dp )
    {
        if ( row == m-1 ) return triangle[row][col]  ;
        
        if ( dp[row][col] != -1 )  return dp[row][col] ;
        int left = triangle[row][col] + findMinTotal( row+1, col, m, n, triangle, dp ) ;
        int right = triangle[row][col] + findMinTotal( row+1, col+1, m, n, triangle, dp ) ;
        
        return dp[row][col] = min( left, right ) ;
        
    }
    
    
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size() ;
        int n = triangle[m-1].size() ;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1)) ;
        return findMinTotal( 0, 0, m, n, triangle, dp ) ;
    }
};