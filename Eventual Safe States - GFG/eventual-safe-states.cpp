//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // kahn's Algorithm 
        // BFS
        vector<int> revGraph[V] ;
        vector<int> indegree(V, 0) ;
        vector<int> ans ;
        queue<int> q;
        
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                
                revGraph[it].push_back(i) ;
            }
        }
        
        for(int i=0; i<V; i++){
            for(auto it: revGraph[i]){
                indegree[it]++ ;
            }
        }
        
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i) ;
            }
        }
        
        while(!q.empty()){
            int node = q.front() ;
            q.pop() ;
            
            ans.push_back(node) ;
            
            for(auto it: revGraph[node]){
                indegree[it]-- ;
                
                if(indegree[it] == 0){
                    q.push(it) ;
                }
            }
        }
        
        sort(ans.begin(), ans.end()) ;
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