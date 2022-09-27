class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int left =0, right=0, maxLen=INT_MIN, zero= 0 ;
        
        while(right < nums.size()){
            if(nums[right] == 0){
                if(zero < k){
                    zero++ ;
                }
                else{
                    while(nums[left++] != 0) ;
                }
            }
            
            maxLen = max(maxLen, right-left+1) ;
            right++ ;
        }
        
        return maxLen ;
        
        
        /*
        int left=0, right=0, maxLen=INT_MIN, key= k ;
        
        while(right<nums.size()){
            
            if(nums[right] == 1)
                right++ ;
            else{
                if(key>0){
                    key-- ;
                    right++ ;
                }
                else{
                    key =k ;
                    maxLen = max(maxLen, right-left+1) ;
                    right++ ;
                    left =right ;
                }
            }
            
            maxLen = max(maxLen, right-left+1) ;
        }
        
        return maxLen ;
        */
        
//         int left =0, right=0, maxLen=INT_MIN, zero= 0 ;
        
//         while(right<nums.size()){
            
//             if(nums[right] == 1)
//                 right++ ;
//             else{
//                 if(zero < k){
//                     zero++ ;
//                     right++ ;
//                 }
//                 else{
//                     // maxLen = max(maxLen, right-left+1) ;
//                     // zero =0 ;
//                     // right = right+1 ;
//                     // left = right ;
                    
//                     while(left <= right && nums[left] != 0){
//                         left++ ;
//                     }
//                     right++ ;
//                     left++ ;
//                 }   
//             }
//         }
        
//         return maxLen ;
    }
};