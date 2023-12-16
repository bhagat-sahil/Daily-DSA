class Solution {
public:
    
    
    int findAns( int i, int j, vector<vector<int>>& grid,vector<vector<int>>&visited )
    {
        bool flag = false ;
        int m = grid.size() ;
        int n = grid[0].size() ;
        queue<pair<int,int>>q ;
        q.push({i,j}) ;
        visited[i][j] = 1 ;
        int drow[] = {0,0,-1,1} ;
        int dcol[] = {1,-1,0,0} ;
        
        while ( !q.empty())
        {
            int nrow = q.front().first ;
            int ncol = q.front().second ;
            q.pop() ;
            if ( nrow == 0 || nrow == m-1 || ncol == 0 || ncol == n-1 ) flag = true ;
            
            for ( int a = 0 ; a < 4 ; a++ )
            {
                int r = nrow + drow[a] ;
                int c = ncol + dcol[a] ;
                
                if ( r>=0 && r<m && c>=0 && c<n && visited[r][c] == -1 && grid[r][c] == 0 )
                {
                    q.push({r,c}) ;
                    visited[r][c] = 1 ;
                }
                
            }
        }
        if ( flag ) return 0 ;
        else return 1 ;
    }
    
    int closedIsland(vector<vector<int>>& grid) 
    {
        int m = grid.size() ;
        int n = grid[0].size() ;
        int ans = 0 ;
        vector<vector<int>>visited(m,vector<int>(n,-1)) ;
        for ( int i = 1 ; i < m-1 ; i++ )
        {
            for ( int j = 1 ; j < n-1 ; j++ )
            {
                if ( grid[i][j] == 0 && visited[i][j] == -1 )
                {
                    ans = ans + (findAns(i,j,grid,visited)) ;
                }
            }
        }
        return ans ;
        
    }
};