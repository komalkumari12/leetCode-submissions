/* Approach
    1.Use of concept of tabulation with constant space
*/    

class Solution {
public:    
    int fib(int n) {
        int prev2 = 0 ;
        int prev = 1 ;
        
        
        if(n==0) return prev2 ;
        
        for(int i=2 ; i<=n ;i++){
            int curri = prev + prev2 ;
            prev2 = prev ;
            prev = curri ;
        }
        return prev ;
    }
};