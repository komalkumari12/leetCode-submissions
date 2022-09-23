class Solution {
public:
    int bits(int num){
        return log2(num)+1 ;
    }
        
    int concatenatedBinary(int n) {
        long ans =0 ;
        long mod = 1e9 + 7 ;
        
        for(int i=1; i<=n; i++){
            int numberOfBits = bits(i) ;
            ans = ((ans << numberOfBits) % mod + i) %mod ;
        }
        
        return ans ;
    }
};