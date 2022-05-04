class Solution {
public:
    int length(int ind, int prev,  int len, vector<int>& nums, vector<vector<int>>& dp){
        if(ind == nums.size()) return 0 ;
        
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1] ;
        
        len = length(ind+1, prev, len, nums, dp) ;
        
        if(prev == -1  ||  nums[ind] > nums[prev]){
            len = max(len, 1+ length(ind+1, ind, len, nums, dp)) ;
        }
        
        return dp[ind][prev+1] = len ;
    }
        
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1)) ;
        
        return length(0, -1, 0, nums, dp) ;
    }
};