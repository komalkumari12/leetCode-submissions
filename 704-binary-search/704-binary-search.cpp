class Solution {
public:
    int binarySearch(vector<int>&nums ,int start ,int end ,int target){
        if(start > end) return -1 ;
            
            int mid =start + (end-start)/2 ;
            if(nums[mid] == target ) return mid;
            if(target < nums[mid])   return binarySearch(nums , start ,mid-1 ,target) ;
            else return binarySearch(nums , mid+1 ,end ,target) ;
    }
        
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0 ,nums.size()-1 ,target) ;
    }
};
