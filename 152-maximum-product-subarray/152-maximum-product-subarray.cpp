class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int maxProd=ans;
        int minProd=ans;
        
        for(int i=1; i<nums.size() ;i++){
            
            if(nums[i] < 0)
                swap(maxProd ,minProd) ;
            
            maxProd=max(maxProd*nums[i] ,nums[i]) ;
            minProd=min(minProd*nums[i] ,nums[i]) ;
            
            
            
            ans=max(ans,maxProd) ;
        }
        return ans ;
    }
};