class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        //making adj vector
        int m = prerequisites.size() ;
        vector<vector<int>>adj(numCourses) ;
        
        //BY THIS METHOD OF MAKING ADJ ANSWER IS GIVING WRONG PTA NHI KYU
        // for ( int i = 0 ; i < m ; i++ )
        // {
        //     for ( auto it : prerequisites[i] )
        //     {
        //         if ( it != i )
        //         adj[i].push_back(it) ;
        //     }
        // }
        
        
        
        //SHORT LOOKING BUT COMPLEX TO MAKE ADJ- STRIVER VID
        for(auto edge : prerequisites)
        {
            adj[edge[1]].push_back(edge[0]);
            
        }
        
        
        //making indegree vector
        vector<int>indegree(numCourses) ;
        for ( int i = 0 ; i < numCourses ; i++ )
        {
            for ( auto child : adj[i] )
                indegree[child]++ ;
        }
        
        //topo sort
        int count = 0 ;
        queue<int>q ;
        
        for ( int i = 0 ; i < numCourses ; i++ )
        {
            if ( indegree[i] == 0 ) q.push(i) ;
        }
        while ( !q.empty())
        {
            int node = q.front() ;
            count++ ;
            q.pop() ;
            for ( auto it : adj[node] )
            {
                indegree[it]-- ;
                if ( indegree[it] == 0 ) q.push(it) ;
            }
        }
        if ( count == numCourses ) return true ;
        else return false ;
    }
};