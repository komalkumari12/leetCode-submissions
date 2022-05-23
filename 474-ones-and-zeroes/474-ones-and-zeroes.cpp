class Solution {
public:
    vector<pair<int,int>>v;
    int dp[601][101][101];
    
    int solve(int ind, int m, int n)
    {
        if(m < 0 || n < 0) return -1 ;
        
        if(ind >= v.size()) return 0 ;
        
        if(dp[ind][m][n] != -1) return dp[ind][m][n] ;
          
        int cnt = max(solve(ind+1, m, n), 1 + solve(ind+1, m-v[ind].first, n-v[ind].second));
        return dp[ind][m][n] = cnt;
    }
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        for(auto s:strs)
        {
            int zero=count(s.begin(),s.end(),'0');
            v.push_back({zero,s.size()-zero});
        }
        memset(dp,-1,sizeof(dp));
        return solve(0,m,n);
    }
};