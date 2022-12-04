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
    bool inRange(int i, int j, int n, int m){
        if(i>=0 && j>=0 && i<n && j<m)
            return true ;
        return false ; 
    }
    
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size() ;
        DisjoinSet ds(n*m +1) ;
        
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                
                int node = row*m + col;
                
                if(grid[row][col] == 1){
                    int new_row = row ;
                    int new_col = col+1 ;
                    
                    if(inRange(row, col+1, n, m) && (grid[row][col+1] == 1  ||  grid[row][col+1] == 3  || grid[row][col+1] == 5)){
                        int adjNode = new_row*m + new_col ;
                        ds.unionBySize(node, adjNode) ;
                    }
                }
                
                if(grid[row][col] == 2){
                    int new_row = row+1 ;
                    int new_col = col ;
                    
                    if(inRange(row+1, col, n, m) && (grid[row+1][col] == 2  ||  grid[row+1][col] == 5  || grid[row+1][col] == 6)){
                        int adjNode = new_row*m + new_col ;
                        ds.unionBySize(node, adjNode) ;
                    }
                }
                
                if(grid[row][col] == 3){
                    int new_row = row+1 ;
                    int new_col = col ;
                    
                    if(inRange(row+1, col, n, m) && (grid[row+1][col] == 2  ||  grid[row+1][col] == 5  || grid[row+1][col] == 6)){
                        int adjNode = new_row*m + new_col ;
                        ds.unionBySize(node, adjNode) ;
                    }
                }
                
                if(grid[row][col] == 4){
                    int new_row = row+1 ;
                    int new_col = col ;
                    
                    if(inRange(row+1, col, n, m) &&  (grid[row+1][col] == 2  ||  grid[row+1][col] == 5  || grid[row+1][col] == 6)){
                        int adjNode = new_row*m + new_col ;
                        ds.unionBySize(node, adjNode) ;
                    }
                    
                    new_row = row ;
                    new_col = col+1 ;
                    
                    if(inRange(row, col+1, n, m) && (grid[row][col+1] == 1  ||  grid[row][col+1] == 3  || grid[row][col+1] == 5)){
                        int adjNode = new_row*m + new_col ;
                        ds.unionBySize(node, adjNode) ;
                    }
                }
                
                if(grid[row][col] == 6){
                    int new_row = row ;
                    int new_col = col+1 ;
                    
                    if(inRange(row, col+1, n, m) &&  (grid[row][col+1] == 1  ||  grid[row][col+1] == 3  || grid[row][col+1] == 5)){
                        int adjNode = new_row*m + new_col ;
                        ds.unionBySize(node, adjNode) ;
                    }
                }
            }
        }
        
        int node = (n-1)*m + (m-1) ;
        int par = ds.findParent(node) ;

        return ds.findParent(0) == par ? true : false ;
    }
};