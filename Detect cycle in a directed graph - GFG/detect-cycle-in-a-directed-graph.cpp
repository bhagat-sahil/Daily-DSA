//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool dfs( int ind, vector<int>&visited, vector<int> adj[] )
    {
        //2 means visited as well as path visited
        visited[ind] = 2 ;
        
        for ( auto child : adj[ind] )
        {
            
            if ( visited[child] == -1 )
            {
                if ( dfs(child,visited,adj) ) return true ;
            }
            else if ( visited[child] == 2 ) return true ;
        }
        
        //1 means its visited but not path visited
        visited[ind] = 1 ;
        return false ;
    }
  
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        
        vector<int>visited(V,-1) ;
        
        for ( int i = 0 ; i < V ; i++ )
        {
            if ( visited[i] == -1 )
            {
                if ( dfs(i,visited,adj) )   return true ;
            }
        }
        return false ;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends