// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  void dfsFun(int node, vector<int>& vis, vector<int>& dfs, vector<int> adj[]){
      dfs.push_back(node) ;
      vis[node] = 1 ;
      
      for(auto it: adj[node]){
          if(!vis[it]){
              dfsFun(it, vis, dfs, adj) ;
          }
      }
  }
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V+1, 0) ;
        vector<int> dfs ;
        
        dfsFun(0, vis, dfs, adj) ;
        return dfs ;
    }
};

// { Driver Code Starts.
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
}  // } Driver Code Ends