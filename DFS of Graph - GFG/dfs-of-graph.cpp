//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  void dfs(int currentNode, vector<int>&vist, vector<int> adj[], vector<int>&ans)
  {
      vist[currentNode] = 1;
      ans.push_back(currentNode);
      
      for(auto adjacentNode : adj[currentNode])
      {
          if(vist[adjacentNode] == 0)
            dfs(adjacentNode,vist,adj,ans);
      }
  }
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) 
    {
        vector<int>vist(V,0);
        vector<int>ans;
        
        for(int currentNode = 0; currentNode < V; currentNode++)
        {
            if(vist[currentNode] == 0)
                dfs(currentNode,vist,adj,ans);
        }
        return ans;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends