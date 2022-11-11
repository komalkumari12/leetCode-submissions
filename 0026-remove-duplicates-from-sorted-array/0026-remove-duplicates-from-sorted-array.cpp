class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int e=0; 
        
        for(int i= 0; i<nums.size() ; i++){
            if( e==0 || nums[i]!=nums[e-1]){
                nums[e]= nums[i] ;
                e++ ;
            }
        }
        return e ;
    }
};