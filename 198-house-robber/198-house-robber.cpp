class Solution {
public:
    int houseRob(int ind ,vector<int>& nums,vector<int>& dp){
        if(ind == 0) return nums[ind] ;
        if(ind<0) return 0 ;
        
        if(dp[ind] != -1) return dp[ind] ;
        
        int take= nums[ind] + houseRob(ind-2 ,nums ,dp) ;
        int non_take = 0 + houseRob(ind-1 ,nums, dp) ;
        
        return dp[ind] = max(take, non_take) ;
    }
    int rob(vector<int>& nums) {
        vector<int> dp (nums.size()+1 ,-1) ;
        
        return houseRob(nums.size()-1 ,nums,dp) ;
    }
};