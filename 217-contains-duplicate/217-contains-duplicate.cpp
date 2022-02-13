class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> hash ;
        
        for(int i=0; i<nums.size() ;i++){
            if(hash.find(nums[i]) != hash.end()) return true ;
            else hash[nums[i]]++ ;
        }
        return false;
    }
};
