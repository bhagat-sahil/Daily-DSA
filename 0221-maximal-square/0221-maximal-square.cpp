class Solution {
public:
    
    int maxSquare( int curRow, int curCol, int row, int col, vector<vector<char>>&matrix, vector<vector<int>>&dp )
    {
        if ( curRow >= row || curCol >= col || matrix[curRow][curCol] == '0' )   return 0 ;
        
        if ( dp[curRow][curCol] != -1 ) return dp[curRow][curCol] ;
        
        int down = 1+ maxSquare( curRow+1, curCol, row, col, matrix, dp ) ;
        int right = 1+ maxSquare( curRow, curCol+1, row, col, matrix, dp ) ;
        int diagonal = 1+ maxSquare( curRow+1, curCol+1, row, col, matrix, dp ) ;
        
        return dp[curRow][curCol] = min(down,min(right,diagonal)) ;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size() ;
        int col = matrix[0].size() ;
        int ans = 0 ;
        vector<vector<int>>dp(row,vector<int>(col,-1)) ;
        for ( int i = 0 ; i < row ; i++ )
        {
            for ( int j = 0 ; j < col ; j++ )
            {
                ans = max( ans, maxSquare( i, j, row, col, matrix, dp )) ;
            }
        }
        return ans*ans ;
    }
};