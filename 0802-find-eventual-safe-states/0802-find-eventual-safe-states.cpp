class Solution {
public:
    
    
    bool dfs( int i, vector<int>&visited, vector<int>&pathVisited, vector<int>&ans, vector<vector<int>>& graph )
    {
        visited[i] = 1 ;
        pathVisited[i] = 1 ;
        for ( auto child : graph[i] )
        {
            if ( pathVisited[child] == 1 ) return true ;
            if ( !visited[child] )
            {
                if (dfs( child, visited, pathVisited, ans, graph ))
                    return true ;
            }
        }
        ans.push_back(i) ;
        pathVisited[i] = 0 ;
        return false ;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int m = graph.size() ;
        vector<int>visited(m,0) ;
        vector<int>pathVisited(m,0) ;
        vector<int>ans ;
        for ( int i = 0 ; i < m ; i++ )
        {
            if ( !visited[i])
                dfs( i, visited, pathVisited, ans, graph ) ;
        }
        sort(ans.begin(),ans.end()) ;
        return ans ;
    }
};