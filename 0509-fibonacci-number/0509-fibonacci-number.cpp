class Solution {
public:
    int fib(int num) {
        if(num == 0)    return 0 ;
        
        vector<int>dp(num+1) ;
        int prev2 =0 ;
        int prev1 =1 ;
        
        for(int i=2; i<=num; i++){
            int curr = prev1 + prev2 ;
            
            prev2 = prev1 ;
            prev1 = curr ;
        }
        
        return prev1 ;
    }
};