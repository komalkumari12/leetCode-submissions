class Solution {
public:
    int minOper(int ind1, int ind2, string w1, string w2, vector<vector<int>>& dp){
        if(ind1 < 0) return ind2+1 ;
        if(ind2 < 0) return ind1+1 ;
        
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2] ;
        
        if(w1[ind1] == w2[ind2])
            return dp[ind1][ind2] = minOper(ind1-1, ind2-1, w1, w2, dp) ;
        
            // delete
            // insert   
            // replace
            return dp[ind1][ind2] = 1+ min(minOper(ind1-1, ind2, w1, w2, dp), min(minOper(ind1-1, ind2-1, w1, w2, dp),minOper(ind1, ind2-1, w1, w2, dp))) ;
    }
        
    int minDistance(string word1, string word2) {
        int m = word1.size() ;
        int n = word2.size() ;
        
        vector<vector<int>> dp(m ,vector<int>(n ,-1)) ;
            
        return minOper(m-1, n-1, word1, word2, dp) ;
    }
};