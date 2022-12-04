class Solution {
    int dr[4] = {0, -1, 0, 1} ;
    int dc[4] = {-1, 0, 1, 0} ;
    
    bool inRange(int i, int j, int n, int m){
        if(i>=0 && j>=0 && i<n && j<m)
            return true ;
        return false ; 
    }
    
    bool checkCycle(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& grid){
        //BFS
        int n = grid.size() ;
        int m = grid[0].size() ;
        
        queue<pair<pair<int,int>, pair<int,int>>> q;
        q.push({{i, j}, {-1, -1}}) ;
        vis[i][j]=1 ;
        
        while(!q.empty()){
            int node_row = q.front().first.first ;
            int node_col = q.front().first.second ;
            int par_row = q.front().second.first ;
            int par_col = q.front().second.second ;
            q.pop() ;
            
            for(int ind=0; ind<4; ind++){
                int new_row = node_row + dr[ind] ;
                int new_col = node_col + dc[ind] ;
                
                if(!inRange(new_row, new_col, n, m) || grid[new_row][new_col] != grid[node_row][node_col])
                    continue ;
                
                if(vis[new_row][new_col]!=1){
                    //not visited
                    vis[new_row][new_col]=1 ;
                    q.push({{new_row, new_col}, {node_row, node_col}}) ;
                }
                else{
                    if((new_row != par_row) && (new_col != par_col))
                        return true ;
                }
            }
        }
        
        return false ;
    }
        
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        vector<vector<int>> vis(n, vector<int>(m, 0)) ;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j]){
                    if(checkCycle(i, j, vis, grid))
                        return true ;
                }
            }
        }
        
        return false ;
    }
};