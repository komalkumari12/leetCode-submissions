class Solution {
    vector<vector<int>> ans ;
public:
    void sets(vector<int>& nums, int index , vector<int>& ds){
        if(index == nums.size()){
            ans.push_back(ds) ;
            return ;
        }
        
        ds.push_back(nums[index]) ;
        sets(nums, index+1 , ds) ;
        ds.pop_back() ; 
        sets(nums, index+1 , ds) ;
    }
    
//     temp.push_back(nums[start]);
//         subsets(nums, cache, temp, start + 1);
//         // choice 2, drop it
//         temp.pop_back();
//         subsets(nums, cache, temp, start + 1);
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds ;
        sets(nums, 0 ,ds) ;
        
        return ans ;
    }
};
