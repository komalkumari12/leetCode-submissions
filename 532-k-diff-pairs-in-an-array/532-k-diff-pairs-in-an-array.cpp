class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count= 0 ;
        sort(nums.begin() ,nums.end()) ;
        int i =0; 
        int j=1 ;
        
        while(i < nums.size()  &&  j < nums.size()){
            int diff = abs(nums[j] - nums[i]) ;
            if(diff == k){
                count++ ;
                i++ ;
                j++ ;
                while(j < nums.size()  &&  nums[j] == nums[j-1]) j++ ;
            }
            else if(diff > k){
                i++ ;
                if(i == j) j++ ;
            }
            else j++ ;
        }
        return count ;
    }
};