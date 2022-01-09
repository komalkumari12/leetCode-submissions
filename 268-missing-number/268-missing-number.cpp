class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size=nums.size(),i ;
        
        sort(nums.begin(), nums.end()) ;
        
        for(i=0; i<size ;i++){
            if(nums[i]!=i)
                break ;
        }
        return i ;
    }
};