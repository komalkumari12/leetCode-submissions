class Solution {
public:
    int uniquePaths(int i ,int j ,vector<vector<int>>& obstacleGrid ,vector<vector<int>>& dp){
        if(i>=0  &&  j>=0  &&  obstacleGrid[i][j] == 1) return 0 ;
        if(i==0  &&  j==0) return 1 ;
        if(i<0  ||  j<0) return 0 ;
        
        if(dp[i][j] != -1) return dp[i][j] ;
        
        int up = uniquePaths(i-1 ,j ,obstacleGrid ,dp) ;
        int left = uniquePaths(i ,j-1 ,obstacleGrid ,dp) ;   
        
        return dp[i][j] = up + left ;
    }
        
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size() ;
        int col =obstacleGrid[0].size() ;
        vector<vector<int>> dp (row ,vector<int> (col ,-1)) ;
        
        return uniquePaths(row-1,col-1 , obstacleGrid ,dp) ;
    }
};