class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        
        //making adj vector
        int m = prerequisites.size() ;
        vector<vector<int>>adj(numCourses) ;
        
        
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
        vector<int>ans ;
        queue<int>q ;
        int count = 0 ;
        
        for ( int i = 0 ; i < numCourses ; i++ )
        {
            if ( indegree[i] == 0 ) q.push(i) ;
        }
        while ( !q.empty())
        {
            int node = q.front() ;
            ans.push_back(node) ;
            count++ ;
            q.pop() ;
            for ( auto it : adj[node] )
            {
                indegree[it]-- ;
                if ( indegree[it] == 0 ) q.push(it) ;
            }
        }
        vector<int>a ;
        if ( count == numCourses ) return ans ;
        
        else return a ;
        
    }
};