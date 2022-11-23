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

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DisjoinSet ds(26) ;
        
        int n = equations.size() ;
        for(int i=0; i<n; i++){
            string str = equations[i] ;
            
            if(str[1] == '='){
                int node = str[0] - 'a' ;
                int adjNode = str[3] - 'a' ;
                
                ds.unionBySize(node, adjNode) ;
            }
        }
        
        for(int i=0; i<n; i++){
            string str = equations[i] ;
            
            if(str[1] == '!'){
                int node = str[0] - 'a' ;
                int adjNode = str[3] - 'a' ;
                
                if(ds.findParent(node) == ds.findParent(adjNode))
                    return false ;
            }
        }
        
        return true ;
    }
};