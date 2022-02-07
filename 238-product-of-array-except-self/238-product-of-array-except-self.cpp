/* Approach
    1. vector ans is first initialised with values of product of left subArray
    2. variable prod takes product of right subArray
*/    
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size()  ;
        vector<int> ans (n) ;
        int prod = 1 ;
        
        for(int i=0 ; i<n; i++){
            ans[i] = prod*nums[i] ;
            prod *= nums [i] ;
        }
        prod =1 ;
        for(int i = n-1 ; i>0 ;i--){
            ans[i] = ans[i-1]* prod;
            prod *= nums[i] ;
        }
        ans[0] =prod ;
                        
        return ans ;
    }
};