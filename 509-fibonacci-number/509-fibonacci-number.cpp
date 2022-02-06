/* Approach
    1.Use of concept of memoization
*/    

class Solution {
public:
    int fibo(vector<int>& dp ,int n){
        if(n <= 1) return n ;
        
        if(dp[n] != -1) return dp[n] ;
        return dp[n] = fibo(dp,n-1) + fibo(dp ,n-2) ;
    }
        
    int fib(int n) {
        vector<int> dp(n+1 ,-1) ;
        return fibo(dp, n) ; 
    }
};