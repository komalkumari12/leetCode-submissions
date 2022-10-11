class Solution {
public:
    int fibonacciNum(int num, vector<int>& dp){
        if(num <= 1)
            return num ;
        
        if(dp[num] != -1)
            return dp[num] ;
        
        return dp[num] = fibonacciNum(num-1, dp) + fibonacciNum(num-2, dp) ;
    }
    int fib(int num) {
        
        vector<int> dp(num+1, -1) ;
        return fibonacciNum(num, dp) ;
    }
};