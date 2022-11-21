class DisjoinSet{
    public:
        vector<int> parent, rank, size ;
    
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

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n) ;
        DisjoinSet ds(n) ;
        
        int extraEdges =0 ;
        for(int i=0; i<connections.size(); i++){
            int u = connections[i][0] ;
            int v = connections[i][1] ;
                
            if(ds.findParent(u) != ds.findParent(v)){
                ds.unionBySize(u, v) ;
            }
            else{
                extraEdges++ ;
            }
        }
        
        int components =0 ;
        for(int i=0; i<n; i++){
            if(ds.parent[i] == i)
                components++ ;
        }
        
        int reqEdges = components -1 ;
        if(reqEdges <= extraEdges)
            return reqEdges ;
        return -1 ;
    }
};