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
    int dr[4] = {0, -1, 0, 1} ;
    int dc[4] = {-1, 0, 1, 0} ;
    
    bool inRange(int i, int j, int n, int m){
        if(i>=0 && j>=0 && i<n && j<m)
            return true ;
        return false ; 
    }
    
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size() ;
        DisjoinSet ds(n*m +1) ;
        vector<vector<int>> vis(n, vector<int>(m, 0)) ;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int node = i*m + j;
                vis[i][j] = 1 ;
                
                for(int ind=0; ind<4; ind++){
                    int new_row = i + dr[ind] ;
                    int new_col = j + dc[ind] ;
                    
                    int adjNode = new_row*m + new_col ;
                    if(!inRange(new_row, new_col, n, m) || grid[i][j] != grid[new_row][new_col] || vis[new_row][new_col] ==1)
                        continue ;
                    
                    if(ds.findParent(node) == ds.findParent(adjNode)){
                        // cout<<node<<"  "<<adjNode<<"      "<<i<<" "<<j<<" -> "<<"true"<<endl ;
                        return true ;
                    }
                    
                    ds.unionBySize(node, adjNode) ;
                }
            }
        }
        
        return false ;
    }
};