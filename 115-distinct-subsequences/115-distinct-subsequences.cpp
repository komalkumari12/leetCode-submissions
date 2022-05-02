class Solution {
public:
    int count(int ind1, int ind2, string s, string t, vector<vector<int>>& dp){
        if(ind1 == s.size() && ind2 == t.size()) return 1 ;
        if(ind1 == s.size()) return 0 ;
        if(ind2 == t.size()) return 1 ;
        
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2] ;
        
        if(s[ind1] == t[ind2]){
            return dp[ind1][ind2] = count(ind1+1, ind2+1, s, t, dp) + count(ind1+1, ind2, s, t, dp) ;
        }
        
        return dp[ind1][ind2] = count(ind1+1, ind2, s, t, dp) ;
    }
    
    int numDistinct(string s, string t) {
        int m =s.size() ;
        int n =t.size() ;
        
        vector<vector<int>> dp(m , vector<int>(n, -1)) ;
        return count(0, 0, s, t, dp) ;
    }
};