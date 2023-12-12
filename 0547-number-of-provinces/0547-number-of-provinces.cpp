class Solution {
public:
    
    void findConvert( vector<vector<int>>& isConnected, vector<vector<int>>&adj )
    {
        for ( int i = 0 ; i < isConnected.size() ; i++ )
        {
            for ( int j = 0 ; j < isConnected.size() ; j++ )
            {
                if ( isConnected [i][j] == 1 && j != i )
                    adj[i+1].push_back(j+1) ;
            }
        }
    }
    
    void dfs( int curNode, vector<bool>&visit, vector<vector<int>>& adj )
    {
        visit[curNode] = true ;
        for ( auto it : adj[curNode] )
        {
            if ( !visit[it] )
                dfs(it, visit, adj) ;
        }
        
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size() ;
        vector<bool>visit( n, false ) ;
        int ans = 0 ;
        vector<vector<int>>adj(n+1);
        adj[0] = {0} ;
        findConvert( isConnected, adj ) ;
        for ( int i = 1 ; i <= n ; i++ )
        {
            if ( !visit[i] )
            {
                dfs( i, visit, adj ) ;
                ans++ ;
            }
        }
        return ans ;
    }
};