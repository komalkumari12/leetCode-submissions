class Solution {
public:
    unordered_map<char, int> mpp ;
    int mod=1e9+7;

    long long int f(int n, int ind, char prev, vector<vector<int>> &dp){
        if(ind == n) return 1;
        long long count = 0;
        
        if(dp[mpp[prev]][ind]!=-1) return dp[mpp[prev]][ind]%mod;
        
        if(prev=='a'){
            count += f(n, ind+1, 'e', dp);
        }
        
        if(prev=='e'){
            count += f(n, ind+1, 'a', dp);
            count += f(n, ind+1, 'i', dp);
        }
        if(prev=='i'){
            count += f(n, ind+1, 'a', dp);
            count += f(n, ind+1, 'e', dp);
            count += f(n, ind+1, 'o', dp);
            count += f(n, ind+1, 'u', dp);
        }
        if(prev=='o'){
            count += f(n, ind+1, 'i', dp);
            count += f(n, ind+1, 'u', dp);
        }
        
        if(prev=='u'){
            count += f(n, ind+1, 'a', dp);
        }
        
        return dp[mpp[prev]][ind] = count%mod;
        
    }
    
    int countVowelPermutation(int n) {
        mpp['a'] = 0;
        mpp['e'] = 1;
        mpp['i'] = 2;
        mpp['o'] = 3;
        mpp['u'] = 4;
        vector<vector<int>> dp(5, vector<int>(n+1, -1));
		
        long long cnt = f(n, 1, 'a', dp)
            + f(n, 1, 'e', dp)
            + f(n, 1, 'i', dp)
            + f(n, 1, 'o', dp)
            + f(n, 1, 'u', dp) ; 
        
        return cnt%mod;
        
    }
};