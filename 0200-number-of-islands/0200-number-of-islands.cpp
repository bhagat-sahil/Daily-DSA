class Solution {
public:
    
    void dfs( int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& visited, int m, int n )
    {
        visited[row][col] = true ;
        
        if ( col+1 < n && !visited[row][col+1] && grid[row][col+1] =='1' )
        dfs( row, col+1, grid, visited, m, n ) ;
        if ( row+1 < m && !visited[row+1][col] && grid[row+1][col] =='1' )
        dfs( row+1, col, grid, visited, m, n ) ;
        if ( col-1 >= 0 && !visited[row][col-1] && grid[row][col-1] =='1' )
        dfs( row, col-1, grid, visited, m, n ) ;
        if ( row-1 >=0 && !visited[row-1][col] && grid[row-1][col] =='1' )
        dfs( row-1, col, grid, visited, m, n ) ;
        
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0 ;
        int m = grid.size() ;
        int n = grid[0].size() ;
        vector<vector<bool>>visited(m,vector<bool>(n,false)) ;
        for ( int i = 0 ; i < m ; i++ )
        {
            for (  int j = 0 ; j < n ; j++ )
            {
                if ( !visited[i][j] && grid[i][j] == '1' )
                {
                    dfs( i, j, grid, visited, m, n ) ;
                    ans++ ;
                }
            }
        }
        return ans ;
    }
};