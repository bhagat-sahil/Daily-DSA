class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size() ;
        queue<pair<pair<int,int>,int>>q ;
        vector<vector<int>>visited(m,vector<int>(n,-1)) ;
        int countFresh = 0 ;
        for ( int row = 0 ; row < m ; row++ )
        {
            for ( int col = 0 ; col < n ; col++ )
            {
                if ( grid[row][col] == 2 )
                {
                    q.push({{row,col},0}) ;
                    visited[row][col] = 2 ;
                }
                if ( grid[row][col] == 1 ) countFresh++ ;
            }
        }
        int drow[] = { 0, 0, -1, 1 } ;
        int dcol[] = { 1, -1, 0, 0 } ;
        int time = 0 ;
        int count = 0 ;
        while ( !q.empty())
        {
            int r = q.front().first.first ;
            int c = q.front().first.second ;
            int t = q.front().second ;
            q.pop() ;
            time = t ;
            for ( int i = 0 ; i < 4 ; i++ )
            {
                int nrow = r + drow[i] ;
                int ncol = c + dcol[i] ;
                if ( nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1 && visited[nrow][ncol] != 2 )
                {
                    q.push({{nrow,ncol},t+1}) ;
                    visited[nrow][ncol] = 2;
                    count++ ;
                }
            }
        }
        if ( count != countFresh ) return -1 ;
        return time ;
    }
};