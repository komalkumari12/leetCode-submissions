class Solution {
public:
    bool jumps(int ind ,vector<int>& nums ,vector<int>& dp){
        if(ind==nums.size()-1) return true ;
        if(ind>nums.size()-1) return false ;
        
        if(dp[ind] != -1) return dp[ind] ;
        int jump = ind + nums[ind] ;
        
        for(int i=ind+1 ;i<=jump ;i++){
            bool check =jumps(i ,nums,dp) ;
            
            if(check) return dp[ind] = true ;
        }
        return dp[ind] = false ;
    }
        
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size()+1 ,-1) ;
        
        return jumps(0 ,nums,dp) ;
    }
};
