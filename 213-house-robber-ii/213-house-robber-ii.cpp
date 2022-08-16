class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& dp){
        if(i >= nums.size())
            return 0 ;
        
        if(dp[i] != -1) return dp[i] ;
        
        int rob = solve(i+2, nums, dp) + nums[i];
        int notRob = solve(i+1, nums, dp) ;
        
        return dp[i] = max(rob, notRob) ;
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 1)    return nums[0] ;
        
        int n = nums.size() ;
        vector<int> arr1, arr2;
        vector<int> dp1(n+1, -1), dp2(n+1, -1) ;
        
        for(int i=0; i<n; i++){
            if(i!=0){
                arr1.push_back(nums[i]) ;
            }
            if(i!=n-1){
                arr2.push_back(nums[i]) ;
            }
        }
        
        int maxi = INT_MIN ;
        maxi = max(solve(0, arr1, dp1), solve(0, arr2, dp2));
        
        return maxi ;
    }
};