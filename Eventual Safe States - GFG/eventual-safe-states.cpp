//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(int node, vector<int>& vis, vector<int>& dfsVis, vector<int>& checkSafeNodes, vector<int> adj[]){
        vis[node] =1 ;
        dfsVis[node] = 1 ;
        
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(it, vis, dfsVis, checkSafeNodes, adj))
                return true ;
            }
            else if(dfsVis[it])
                return true ;
        }
        
        checkSafeNodes[node] =1 ;
        dfsVis[node] = 0 ;
        return false ;
    }
    
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // Any node which is the part of the cycle can not be a safe node
        // Question changes to find out if nodes in the cycle which are not present inn the cycle
        // DFS
        
        vector<int> vis(V, 0) ;
        vector<int> dfsVis(V, 0) ;
        vector<int> ans ;
        vector<int> checkSafeNodes(V, 0) ;
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(!dfs(i, vis, dfsVis,checkSafeNodes, adj)){
                    // cycle not present
                    // node is safe node
                }
            }
        }
        
        
        for(int i=0; i<V; i++){
            if(checkSafeNodes[i] == 1){
                ans.push_back(i) ;
            }
        }
        return ans ;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends