class Solution {
    bool inRange(int i, int j, int n, int m){
        if(i>=0 && j>=0 && i<n && j<m)
            return true ;
        return false ; 
    }
    
    bool checkCycle(int i, int j, int n, int m, char tar, vector<vector<int>>& vis, vector<vector<char>>& grid){
        if(!inRange(i, j, n, m) || grid[i][j] != tar)
            return false ;
        
        if(vis[i][j] == 1)   return true ;
        
        vis[i][j] = 1 ;
        char ch = grid[i][j] ;
        grid[i][j] = '1' ;
            
        bool ans = checkCycle(i+1, j, n, m, tar, vis, grid) || 
            checkCycle(i-1, j, n, m, tar, vis, grid) || 
            checkCycle(i, j+1, n, m, tar, vis, grid) || 
            checkCycle(i, j-1, n, m, tar, vis, grid) ;
        
        grid[i][j] = ch ;    
        return ans ;
    }
         
public:
    bool containsCycle(vector<vector<char>>& grid) {
        //DFS
        int n = grid.size() ;
        int m = grid[0].size() ;
        vector<vector<int>> vis(n, vector<int>(m, 0)) ;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j]){
                    if(checkCycle(i, j, n, m, grid[i][j], vis, grid))
                        return true ;
                }
            }
        }
        
        return false ;
    }
};