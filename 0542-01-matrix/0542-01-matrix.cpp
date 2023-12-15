class Solution {
public:
    
    
    
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int m = mat.size() ;
        int n = mat[0].size() ;
        vector<vector<int>>ans(m,vector<int>(n,0)) ;
        vector<vector<int>>visited(m,vector<int>(n,-1)) ;
        queue<pair<pair<int,int>,int>>q ;
        for ( int i = 0 ; i < m ; i++ )
        {
            for ( int j = 0 ; j < n ; j++ )
            {
                if (mat[i][j] == 0) 
                {
                    q.push({{i,j},0}) ;
                    visited[i][j] = 1 ;
                }
                
            }
        }
        while( !q.empty())
        {
            int r = q.front().first.first ;
            int c = q.front().first.second ;
            int t = q.front().second ;
            ans[r][c] = t ;
            q.pop() ;
            int drow[] = { 0, 0, 1, -1 } ;
            int dcol[] = { 1, -1, 0, 0 } ;
            for ( int i = 0 ; i < 4 ; i++ )
            {
                int nrow = r + drow[i] ;
                int ncol = c + dcol[i] ;
                
                if ( nrow>=0 && nrow<m && ncol>=0 && ncol<n &&visited[nrow][ncol] != 1 )
                {
                    q.push({{nrow,ncol},t+1}) ;
                    visited[nrow][ncol] = 1 ;
                }
            }
        }
        return ans ;
    }
};