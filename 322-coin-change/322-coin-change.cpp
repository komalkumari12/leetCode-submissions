class Solution {
    int countCoins(int ind , int target , vector<int> &coins , vector<vector<int>> &dp){
        if(ind==0){
            if(target % coins[0] == 0)   return target/coins[0] ;
            else return 1e9 ;
        }
        
        if(dp[ind][target] != -1) return dp[ind][target] ;
        
        int non_pick= countCoins(ind-1 , target, coins,dp) + 0 ;
        int pick=INT_MAX ;
        if(target >= coins[ind])
            pick=countCoins(ind , target-coins[ind] , coins,dp) + 1 ;
        
        return dp[ind][target] = min(pick , non_pick) ;
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<vector<int>> dp(coins.size()+1 , vector<int>(amount+1 ,-1)) ;
        
        int ans=countCoins(coins.size()-1 , amount , coins,dp) ;
        
        if(ans >= 1e9) return -1 ;
        else return ans ;
    }
};