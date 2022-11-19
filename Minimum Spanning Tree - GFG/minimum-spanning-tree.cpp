//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjoinSet{
    vector<int> parent, rank, size ;
    public:
        DisjoinSet(int n){
            parent.resize(n+1) ;
            rank.resize(n+1, 0) ;
            size.resize(n+1, 1) ;
            
            for(int i=0; i<n+1; i++)
                parent[i] = i ;
        }
        
        int findParent(int node){
            if(parent[node] == node)
                return node ;
            return parent[node] = findParent(parent[node]) ;
        }
        
        void unionByRank(int u, int v){
            int par_u = findParent(u) ;
            int par_v = findParent(v) ;
            
            if(par_u == par_v)  return ;
            if(rank[par_v] < rank[par_u]){
                parent[par_v] = par_u ;
            }
            else if(rank[par_v] > rank[par_u]){
                parent[par_u] = par_v ;
            }
            else{
                parent[par_v] = par_u ;
                rank[par_u]++ ;
            }
        }
        
        void unionBySize(int u, int v){
            int par_u = findParent(u) ;
            int par_v = findParent(v) ;
            
            if(par_u == par_v)  return ;
            if(size[par_u] < size[par_v]){
                parent[par_u] = par_v ;
                size[par_v] += size[par_u] ;
            }
            else{
                parent[par_v] = par_u ;
                size[par_u] += size[par_v] ;
            }
        }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        DisjoinSet ds(V) ;
        
        vector<pair<int, pair<int,int>>> graph ;
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                int adjNode = it[0] ;
                int wt = it[1] ;
                int node = i ;
                
                graph.push_back({wt, {node ,adjNode}}) ;
            } 
        }
        
        sort(graph.begin(), graph.end()) ;
        int mstWeight =0 ;
        
        for(auto it: graph){
            int wt = it.first ;
            int u = it.second.first ;
            int v = it.second.second ;
            
            if(ds.findParent(u) != ds.findParent(v)){
                ds.unionBySize(u, v) ;
                mstWeight += wt ;
            }
        }
        
        return mstWeight ;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends