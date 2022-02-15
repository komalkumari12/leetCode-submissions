class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singleNum =nums[0] ;
        
        for(int i=1 ; i<nums.size() ;i++)
            singleNum = singleNum ^ nums[i] ;
        
        return singleNum ;
    }
};