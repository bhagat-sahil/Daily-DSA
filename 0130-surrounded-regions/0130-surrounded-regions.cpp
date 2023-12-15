class Solution {
public:
    
    void dfs( int row, int col, vector<vector<char>>&visited, vector<vector<char>>&board)
    {
        int m = board.size() ;
        int n = board[0].size() ;
        visited[row][col] = 'O' ;
        int drow[] = { 0, 0, -1, 1 } ;
        int dcol[] = { 1, -1, 0, 0 } ;
        for ( int i = 0 ; i < 4 ; i++ )
        {
            int r = row + drow[i] ;
            int c = col + dcol[i] ;
            if ( r>=0 && r<m && c>=0 && c<n && visited[r][c] == 'X' && board[r][c] == 'O')
                dfs( r, c, visited, board ) ;
        }
        
    }
        
    void solve(vector<vector<char>>& board)
    {
        int m = board.size() ;
        int n = board[0].size() ;
        vector<vector<char>>visited(m,vector<char>(n,'X')) ;
        for ( int i = 0 ; i < n ; i++ )
        {
            //for first row
            if ( board[0][i] == 'O' && visited[0][i] == 'X' )
                dfs( 0, i, visited, board ) ;
            
            //for last row
            if ( board[m-1][i] == 'O' && visited[m-1][i] == 'X' )
                dfs( m-1, i, visited, board ) ;
        }
        for ( int j = 0 ; j < m ; j++ )
        {
            //for first col
            if ( board[j][0] == 'O' && visited[j][0] == 'X' )
                dfs( j, 0, visited, board ) ;
            
            //for last col
            if ( board[j][n-1] == 'O' && visited[j][n-1] == 'X' )
                dfs( j, n-1, visited, board ) ;
        }
        board = visited ;
    }
};