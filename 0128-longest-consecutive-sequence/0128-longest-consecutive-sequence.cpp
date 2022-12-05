class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //Approach 1: Sorting
        
        int n = nums.size() ;
        if(n == 0)  return 0 ;
        
        sort(nums.begin(), nums.end()) ;
        
        int count =1, maxCount =1 ;
        for(int i=1; i<n; i++){
            if(nums[i-1] == nums[i])    
                continue ;
            
            if(nums[i-1] + 1 == nums[i])
                count++ ;
            else
                count = 1 ;
            
            maxCount = max(maxCount, count) ;
        }
        
        return maxCount ; 
    }
};