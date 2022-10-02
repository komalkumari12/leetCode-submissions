class Solution {
public:
    int MOD = 1000000007;
    int rollDice(vector<vector<int>>&dp,int d, int f, int target){
        
        if(d==0 || target<=0) return (int)(d==target);

        if(dp[d][target]!=-1) return dp[d][target];
        
        int res = 0;
        for(int i=1;i<=f;i++)
            res =  (res + rollDice(dp,d-1,f,target-i))%MOD;                
        
        dp[d][target] = res;
        
        return dp[d][target];
    }
    
    int numRollsToTarget(int d, int f, int target) {

        vector<vector<int>>dp(d+1,vector<int>(target+1,-1));
        return rollDice(dp,d,f,target);
    }
};