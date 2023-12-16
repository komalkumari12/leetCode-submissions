//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void bfs(int src, vector<int>& vis, vector<int> adj[]){
        queue<int> q ;
        q.push(src) ;
        
        while(!q.empty()){
            int node = q.front() ;
            q.pop() ;
            
            vis[node] = 1 ;
            
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it] =1 ;
                    q.push(it) ;
                }
            }
        }
    }
    
    
    int numProvinces(vector<vector<int>> graph, int V) {
        // DFS
        vector<int> adj[V] ;
        
        for(int i=0; i<graph.size(); i++){
            for(int j=0; j<graph[i].size(); j++){
                if(graph[i][j] == 1 && i != j){
                    adj[i].push_back(j) ;
                    adj[j].push_back(i) ;
                }
            }
        }
        
        vector<int> vis(V, 0) ;
        int components = 0 ;
        
        for(int i=0; i<V; i++){
            if(vis[i] == 0){
                components++ ;
                bfs(i, vis, adj) ;
            }
        }
        
        return components ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends