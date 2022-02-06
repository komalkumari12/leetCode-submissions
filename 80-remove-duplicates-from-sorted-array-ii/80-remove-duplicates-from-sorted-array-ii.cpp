class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0 ;
        
        for(int e =0; e< nums.size() ;e++){
            if( i==0 || i==1 || nums[i-2]!=nums[e]){
                nums[i] = nums[e] ;
                i++ ;
            }
        }
        return i ;
    }
};