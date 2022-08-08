//Binary Search

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> bS ;
        bS.push_back(nums[0]) ;
        
        int len=1 ;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > bS.back()){
                len++ ;
                bS.push_back(nums[i]) ;
            }
            else{
                int ind = lower_bound(bS.begin(), bS.end(), nums[i]) - bS.begin();
                bS[ind] = nums[i] ;
            }
        }
        
        return len ;
    }
};