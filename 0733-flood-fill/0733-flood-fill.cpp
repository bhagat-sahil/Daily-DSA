class Solution {
public:
    
    void dfs( int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited, int m, int n, int color )
    {
        visited[row][col] = true ;
        int val = grid[row][col] ;
        grid[row][col] = color ;
        
        
        if ( col+1 < n && !visited[row][col+1] && grid[row][col+1] == val )
        dfs( row, col+1, grid, visited, m, n, color ) ;
        if ( row+1 < m && !visited[row+1][col] && grid[row+1][col] == val )
        dfs( row+1, col, grid, visited, m, n, color ) ;
        if ( col-1 >= 0 && !visited[row][col-1] && grid[row][col-1] == val )
        dfs( row, col-1, grid, visited, m, n, color ) ;
        if ( row-1 >=0 && !visited[row-1][col] && grid[row-1][col] == val )
        dfs( row-1, col, grid, visited, m, n, color ) ;
        
    }
    
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int m = image.size() ;
        int n = image[0].size() ;
        vector<vector<bool>>visited(m,vector<bool>(n,false)) ;
        dfs( sr, sc, image, visited, m, n, color ) ;
        return image ;          
    }
};