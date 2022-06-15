class Solution {
    public boolean canJump(int[] nums) {
        int n=nums.length;
        boolean dp[]=new boolean [nums.length];
        dp[n-1]=true;
        
        
        for(int i=n-2;i>=0;i--){

            if(nums[i]+i>=n-1)
                dp[i]=true;
            else
                dp[i]=checkIfPath(i+1,i+nums[i],nums,dp);
            
        }
        
        return dp[0];
    
    }
    
    boolean checkIfPath(int start,int end,int[]nums,boolean[] dp){
        
        for(int i=start;i<=end;i++){

        if(dp[i]==true)
            return true;}
     return false;}
   
}