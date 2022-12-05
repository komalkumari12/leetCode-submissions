class Solution {
    bool inRange(int i, int j, int n, int m){
        if(i>=0 && j>=0 && i<n && j<m)
            return true ;
        return false ; 
    }
    
    void dfs(int i, int j, int n, int m, vector<vector<int>>& grid){
        if(!inRange(i, j, n, m) || grid[i][j] != 0)
            return ;
        
        grid[i][j] = 2 ;
        
        dfs(i+1, j, n, m, grid) ;
        dfs(i-1, j, n, m, grid) ;
        dfs(i, j+1, n, m, grid) ;
        dfs(i, j-1, n, m, grid) ;
    }
        
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        
        for(int i=0; i<n; i++){
            if(grid[i][0] == 0)
                dfs(i, 0, n, m, grid) ;
            if(grid[i][m-1] == 0)
                dfs(i, m-1, n, m, grid) ;
        }
        
        for(int i=0; i<m; i++){
            if(grid[0][i] == 0)
                dfs(0, i, n, m, grid) ;
            if(grid[n-1][i] == 0)
                dfs(n-1, i, n, m, grid) ;
        }
        
        int component=0 ;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0){
                    component++ ;
                    dfs(i, j, n, m, grid) ;
                }
            }
        }
        
        return component ;
    }
};