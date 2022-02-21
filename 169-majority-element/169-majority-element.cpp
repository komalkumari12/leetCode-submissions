// Moore's Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0 ;
        int ele =0 ;
        
        for(int i=0; i<nums.size() ;i++){
            if(count==0)     ele=nums[i] ;
            if(ele==nums[i]) count++ ;
            else             count-- ;
        }
        
        return ele ;
    }
};