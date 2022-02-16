class Solution {
public:
    int minimumPathSum(int i ,int j , vector<vector<int>>& triangle ,vector<vector<int>>& dp){
        if(i == triangle.size()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j] ;
        
        int down = triangle[i][j] + minimumPathSum(i+1 ,j ,triangle ,dp) ;
        int diagonal = triangle[i][j] + minimumPathSum(i+1 ,j+1 ,triangle ,dp) ;
        
        return dp[i][j] = min(down, diagonal) ;
    }
        
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp (triangle.size() ,vector<int> (triangle.size() ,-1)) ;
        
        return minimumPathSum(0,0,triangle ,dp) ;
    }
};