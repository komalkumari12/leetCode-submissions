class Solution {
public:
    int solve(int i, vector<int>& costs, vector<int>& dp){
        if(i>=costs.size()) return 0 ;
        
        if(dp[i] != -1) return dp[i] ;
        
        int oneJump =solve(i+1, costs, dp) + costs[i] ;
        int twoJumps = solve(i+2, costs, dp) + costs[i] ;
        
        return dp[i] =  min(oneJump, twoJumps) ;
    }
        
    int minCostClimbingStairs(vector<int>& costs) {
        vector<int> dp(costs.size()+1, -1) ;
        
        return min(solve(0, costs, dp), solve(1, costs, dp)) ;
    }
};