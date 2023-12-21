class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        int m = graph.size() ;
        int n = graph[0].size() ;
        vector<int>indegree(m) ;
        vector<vector<int>>adj(m) ;
        for ( int i = 0 ; i < m ; i++ )
        {
            for ( auto it : graph[i] )
            {
                adj[it].push_back(i) ;
                indegree[i]++ ;
            }
                
        }
        
        queue<int>q ;
        for ( int i = 0 ; i < m ; i++ )
        {
            if (indegree[i] == 0)
                q.push(i) ;
        }
            
        vector<int>safeNodes ;
        
        while( !q.empty())
        {
            int node = q.front() ;
            q.pop() ;
            safeNodes.push_back(node) ;
            for ( auto child : adj[node])
            {
                indegree[child]-- ;
                if ( indegree[child] == 0 ) q.push(child) ;
            }
        }
        sort(safeNodes.begin(),safeNodes.end()) ;
        return safeNodes ;
        
    }
};



































