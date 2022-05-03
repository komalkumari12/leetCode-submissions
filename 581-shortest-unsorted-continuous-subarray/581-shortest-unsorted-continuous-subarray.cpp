class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int low = nums[0];
        int high = nums[n-1];
    
        int start = 0;
        int end = -1;
    
        for(int i=1; i<n; i++){
            if(low > nums[i]){  
                end = i;  
            }
            else
                low = nums[i];
        }
        
        for(int i = n-2 ;i >= 0 ;i--){
            if(high < nums[i])          
                start = i;        
            else
                high = nums[i];
        }
        return (end - start + 1);
    }
};