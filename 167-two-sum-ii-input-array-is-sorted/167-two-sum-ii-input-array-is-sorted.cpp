class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2) ;
        int front= 0; 
        int last=nums.size()-1 ;
        
        while(front < last){
            if(nums[front] + nums[last] == target){
                ans[0] = front+1 ;
                ans[1] = last+1 ;
                return ans ;
            }
            if(nums[front] + nums[last] < target)  front++ ;
            else last-- ;
        }
        return ans ;
    }
};