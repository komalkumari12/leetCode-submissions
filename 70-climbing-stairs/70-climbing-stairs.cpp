class Solution {
public:
    int solve(int i ,vector<int>& dp){
        if(i==0) return 1 ;
        if(i<0) return 0 ;
        
        if(dp[i] != -1) return dp[i] ;
        
        int one_step = solve(i-1 ,dp) ;
        int two_step = solve(i-2 ,dp) ;
        
        return dp[i] = one_step + two_step ;  
    }
    
    int climbStairs(int n) {
        vector<int> dp (n+1 ,-1) ;
        
        return solve(n ,dp) ;
    }
};