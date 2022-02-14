class Solution {
public:
    int PathSum(int i, int j ,vector<vector<int>>& grid,vector<vector<int>>& dp){
       if(i==0 && j==0) return grid[i][j] ;
       if(i<0 || j<0) return 1000 ;
        
       if(dp[i][j] != -1) return dp[i][j] ;
        
       int up = grid[i][j] +  PathSum(i-1 ,j ,grid, dp) ;
       int left = grid[i][j] +  PathSum(i ,j-1 ,grid, dp) ; 
        
       return dp[i][j] = min(up,left) ;
    }
        
    int minPathSum(vector<vector<int>>& grid) {
        int row =grid.size() ;
        int col = grid[0].size() ;
        
        vector<vector<int>> dp (row ,vector<int> (col ,-1)) ;
        
        return PathSum(row-1,col-1 ,grid, dp) ;
    }
};