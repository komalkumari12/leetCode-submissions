// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // vector<vector<int>> graph(V+1) ;
        vector<int> vis(V+1, 0) ;
        
        // for(int i=0; i<adj.size(); i++){
        //     int u = adj[i][0] ;
        //     int v = adj[i][1] ;
            
        //     graph[u].push_back(v) ; 
        // }
        
        vector<int> bfs ;
                queue<int> q;
                q.push(0) ;
            
                while(!q.empty()){
                    int node = q.front() ;
                    q.pop();
                    bfs.push_back(node) ;
                    
                    for(auto it: adj[node]){
                        if(!vis[it]){
                            vis[it] = 1 ;
                            q.push(it) ;
                        }
                    }
                }
            
        
        
        return bfs ;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends