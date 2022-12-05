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
    long long countPairs(int n, vector<vector<int>>& edges) {
        DisjoinSet ds(n) ;
        int m = edges.size() ;
        
        for(int i=0; i<m; i++){
            int u = edges[i][0] ;
            int v = edges[i][1] ;
            
            ds.unionBySize(u, v) ;
        }
        
        long long count =0 ;
        for(int i=0; i<n; i++){
            int size = n - ds.size[ds.findParent(i)] ;
            count += size ;
        }
        
        return count/2 ;
    }
};