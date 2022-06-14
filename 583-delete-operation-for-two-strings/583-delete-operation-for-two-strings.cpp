class Solution {
public:
    int solve(int i, string word1, int j, string word2, vector<vector<int>>& dp){
        if(i < 0 || j < 0)
            return 0 ;
        
        if(dp[i][j] != -1) return dp[i][j] ;
        
        if(word1[i] == word2[j])
            return dp[i][j] = 1+ solve(i-1, word1, j-1, word2, dp) ;
        else
            return dp[i][j] = max(solve(i-1, word1, j, word2, dp), solve(i, word1, j-1, word2, dp)) ;
    }
        
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, -1)) ;
        
        int lcs = solve(word1.size()-1, word1, word2.size()-1, word2, dp) ;
        
        return word1.size() - lcs + word2.size() - lcs ;
    }
};