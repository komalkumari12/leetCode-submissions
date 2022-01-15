class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        sort(nums.begin(), nums.end()) ;
        int result=-1;
        
        for( int i=0; i<nums.size()-1; i++){
            if(nums[i]==nums[i+1])
                result = nums[i] ;
        }
        
        return result ;
    }
};