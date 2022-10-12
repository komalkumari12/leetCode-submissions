class Solution {
public:
    int miniCost(int i, vector<int>& cost, map<int,int>& dp){
        if(i >= cost.size())   return 0 ;
        
        if(dp.find(i) != dp.end())
            return dp[i] ;
        
        int one = cost[i] + miniCost(i+1, cost, dp) ;
        int two = cost[i] + miniCost(i+2, cost, dp) ;
        
        return dp[i] = min(one, two) ; 
    }
        
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size() ;
        map<int,int> dp ;
        
        return min(miniCost(0, cost, dp), miniCost(1, cost, dp)) ;
    }
};