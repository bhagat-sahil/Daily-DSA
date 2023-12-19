class Solution {
public:
    
    bool check( int start,vector<int>&color, vector<vector<int>>& graph )
    {
        queue<int>q ;
        q.push(start) ;
        color[start] = 0 ;
        
        while( !q.empty())
        {
            int cur = q.front() ;
            q.pop() ;
            for ( auto child : graph[cur] ) 
            {
                if ( color[child] == color[cur] )   return false ;
                if ( color[cur] == 0 && color[child] == -1 )
                {
                    q.push(child) ;
                    color[child] = 1 ;
                }
                if( color[cur] == 1 && color[child] == -1)
                {
                    q.push(child) ;
                    color[child] = 0 ;
                }
                
            }
        }
        return true ;
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        int m = graph.size() ;
        vector<int>color(m,-1) ;
        for ( int i = 0 ; i < m ; i++ )
        {
            if ( color[i] == -1 )
            {
                if ( !check(i,color,graph) ) return false ;
            }
        }
        return true ;
    }
};