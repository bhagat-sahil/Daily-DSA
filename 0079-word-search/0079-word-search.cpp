class Solution {
public:
    int m ;
    int n ;
    bool dfs ( int idx, int r, int c, string&word, vector<vector<char>>& board, vector<vector<int>>&vis )
    {
        if ( idx == word.size()-1 )
            return true ;
        
        int drow[] = { 0, 0, 1, -1 } ;
        int dcol[] = { 1, -1, 0, 0 } ;
        for ( int i = 0 ; i < 4 ; i++ )
        {
            int nrow = r + drow[i] ;
            int ncol = c + dcol[i] ; 
            if ( nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] 
                && board[nrow][ncol] == word[idx+1] )
                {
                    vis[nrow][ncol] = 1 ;   
                    if ( dfs ( idx+1, nrow, ncol, word, board, vis ) )
                        return true ;
                    vis[nrow][ncol] = 0 ;   
                }
        }
        return false ;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        m = board.size() ;
        n = board[0].size() ;
        vector<vector<int>> vis(m,(vector<int>(n,0))) ;
        for ( int i = 0 ; i < m ; i++ )
        {
            for ( int j = 0 ; j < n ; j++ )
            {
                if ( board[i][j] == word[0] )
                {
                    vis[i][j] = 1 ;
                    if ( dfs( 0, i, j, word, board, vis ) )    
                        return true ;
                    vis[i][j] = 0 ;  
                }
            }
        }
        return false ;
    }
};