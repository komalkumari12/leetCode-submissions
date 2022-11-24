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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjoinSet aliceDs(n+1) ;
        DisjoinSet bobDs(n+1) ;
        
        sort(edges.begin(), edges.end()) ;
        reverse(edges.begin(), edges.end()) ;
        
        int aliceCount=1, bobCount=1 ;
        int removeEdge =0 ; 
        
        for(auto it : edges){
            int type = it[0] ;
            int u = it[1] ;
            int v = it[2] ;
            
            if(type == 3){
                if(aliceDs.findParent(u) == aliceDs.findParent(v)  &&  bobDs.findParent(u) == bobDs.findParent(v)){
                    removeEdge++ ;
                }
                
                if(aliceDs.findParent(u) != aliceDs.findParent(v)){
                    aliceDs.unionBySize(u, v) ;
                    aliceCount++ ;
                }
                if(bobDs.findParent(u) != bobDs.findParent(v)){
                    bobDs.unionBySize(u, v) ;
                    bobCount++ ;
                }
            }
            else if(type == 1){
                if(aliceDs.findParent(u) == aliceDs.findParent(v)){
                    removeEdge++ ;
                }
                if(aliceDs.findParent(u) != aliceDs.findParent(v)){
                    aliceDs.unionBySize(u, v) ;
                    aliceCount++ ;
                }
            }
            else if(type == 2){
                if(bobDs.findParent(u) == bobDs.findParent(v)){
                    removeEdge++ ;
                }
                if(bobDs.findParent(u) != bobDs.findParent(v)){
                    bobDs.unionBySize(u, v) ;
                    bobCount++ ;
                }
            }
        }
        
        if((aliceCount != n)  ||  (bobCount != n))
            return -1 ;
        return removeEdge ;
    }
};