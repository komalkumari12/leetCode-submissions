class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n =nums.size() ;
        vector<int> left(n);   
        vector<int> right(n); 
        vector<int> ans(n) ;
        int prev =1 ;
        
        for(int i=0 ; i<n ;i++){
            left[i] = prev*nums[i] ;
            prev *=nums[i] ;
        }  
        prev =1 ;
        for(int i= n-1 ;i>= 0; i--){
            right[i] = prev*nums[i] ;
            prev *= nums[i] ;  
        }
        
        for(int i= 1; i<n-1 ;i++){
            ans[i] = left[i-1] * right[i+1] ;
        }
        ans[0] = right[1] ;
        ans[n-1] = left [n-2] ;
        
        return ans ;
    }
};