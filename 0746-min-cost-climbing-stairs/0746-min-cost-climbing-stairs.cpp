class Solution {
public:
    int miniCost(int i, vector<int>& cost,vector<int>& dp){
        if(i >= cost.size())   return 0 ;
        
        if(dp[i] != -1)
            return dp[i] ;
        
        int one = cost[i] + miniCost(i+1, cost, dp) ;
        int two = cost[i] + miniCost(i+2, cost, dp) ;
        
        return dp[i] = min(one, two) ; 
    }
        
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size() ;
        vector<int> dp(n+1 ,-1) ;
        
        return min(miniCost(0, cost, dp), miniCost(1, cost, dp)) ;
    }
};