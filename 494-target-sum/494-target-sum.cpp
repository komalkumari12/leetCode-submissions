class Solution {
public:
    int solve(int i, int target, vector<int>& nums){
        if(i>= nums.size()){
            if(target == 0) return 1 ;
            return 0 ;
        }
        
        int take = solve(i+1, target+nums[i], nums) ;
        int notTake = solve(i+1, target-nums[i], nums) ;
        
        return take + notTake ;
    }
        
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return solve(0, target, nums) ;
    }
};