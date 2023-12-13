//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  
    bool findCycle( int start, vector<int> adj[], int V, vector<int>&visited )
    {
        queue<pair<int,int>>q ;
        q.push({start,-1}) ;
        visited[start] = 1 ;
        while ( !q.empty())
        {
            int cur = q.front().first ;
            int parent = q.front().second ;
            q.pop() ;
            for ( auto it : adj[cur])
            {
                if (  visited[it] == -1 )
                {
                    q.push({it,cur}) ;
                    visited[it] = 1 ;
                }
                else if ( parent != it )    return true ;
               
            }
        }
        return false ;
    }
  
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>visited(V,-1) ;
        for ( int i = 0 ; i < V ; i++ )
        {
            if ( visited[i] != 1 )
            {
                if ( findCycle(i, adj, V, visited ) == true )    return true ;
            }
        }
        return false ;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends