//Using map

class Solution {
public:
    int fibonacciNum(int num, map<int,int>& dp){
        if(num <= 1)
            return num ;
        
        if(dp.find(num) != dp.end())
            return dp[num] ;
        
        dp[num] = fibonacciNum(num-1, dp) + fibonacciNum(num-2, dp) ;
        return dp[num] ;
    }
    int fib(int num) {
        
        map<int,int> dp ;
        return fibonacciNum(num, dp) ;
    }
};