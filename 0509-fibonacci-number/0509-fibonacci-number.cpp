class Solution {
public:
    int fib(int num) {
        if(num == 0)    return 0 ;
        
        vector<int>dp(num+1) ;
        dp[0] =0 ;
        dp[1] =1 ;
        
        for(int i=2; i<=num; i++){
            dp[i] = dp[i-1] + dp[i-2] ;
        }
        
        return dp[num] ;
    }
};