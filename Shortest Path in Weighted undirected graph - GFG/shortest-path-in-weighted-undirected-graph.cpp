//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> graph(n+1) ;
        for(int i=0; i<m; i++){
            int u = edges[i][0] ;
            int v = edges[i][1] ;
            int wt = edges[i][2] ;
            
            graph[u].push_back({v, wt}) ;
            graph[v].push_back({u, wt}) ;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq ;
        pq.push({0, 1}) ;
        vector<int> dist(n+1, INT_MAX) ;
        dist[1] = 0 ;
        vector<int> parent(n+1) ;
        
        for(int i=0; i<parent.size(); i++){
            parent[i] = i ;
        }
        
        while(!pq.empty()){
            int distance = pq.top().first ;
            int node = pq.top().second ;
            pq.pop() ;
            
            for(auto it: graph[node]){
                int v = it.first ;
                int wt = it.second ;
                
                if(distance + wt < dist[v]){
                    dist[v] = distance + wt ;
                    pq.push({dist[v], v}) ;
                    
                    parent[v] = node ;
                }
            }
        }
        
        if(dist[n] == INT_MAX)
            return {-1} ;
            
        vector<int> path ;
        int node = n ;
        
        while(parent[node] != node){
            path.push_back(node) ;
            node = parent[node] ;
        }
        path.push_back(1) ;
        reverse(path.begin(), path.end()) ;
        
        return path ;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends