class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = (int) nums.size(), m = (int) multipliers.size();
        vector<int> dp(m + 1);
        
        for (int i = 0; i < m; i++) {
            int mult = multipliers[m - 1 - i];
            for (int j = 0; j < m - i; j++) {
                
                dp[j] = max(
                    mult * nums[j] + dp[j + 1], 
                    mult * nums[j + (n - (m - i))] + dp[j]
                );
            }
        }
        return dp[0];
    }
};