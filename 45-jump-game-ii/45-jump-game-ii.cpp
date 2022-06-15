class Solution {
public:
    long solve(int ind, vector<int>& nums, vector<int>& dp){
        if(ind >= nums.size()) return 10000 ;
        if(ind == nums.size()-1) return 0 ;
        
        if(dp[ind] != -1) return dp[ind] ;
        
        long mini = INT_MAX ;
        
        for(int i=1; i<=nums[ind]; i++){
            mini = min(mini, 1+ solve(ind+i, nums, dp)) ;
        }
        
        return dp[ind] = mini ;
    }
        
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1) ;
        return solve(0, nums, dp) ;
    }
};