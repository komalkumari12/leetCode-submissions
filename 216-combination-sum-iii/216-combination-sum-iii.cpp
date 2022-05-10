class Solution {
public:
    vector<vector<int>> ans ;
    set<vector<int>> st ;
        
    void help(int ind, int k ,int target, vector<int>& nums, vector<int>& ds){
        
        if(ds.size() == k){
            if(target == 0){
                if(st.find(ds) == st.end()){
                    st.insert(ds) ;
                    ans.push_back(ds) ;
                }
                  
            }   
            else return ;
        }
        if(ind == nums.size())  return  ;
        
        //take
        //if(target >= nums[ind]){
            ds.push_back(nums[ind]) ;
            help(ind+1, k, target - nums[ind], nums, ds) ;
        //}
        
        ds.pop_back() ;
        help(ind+1, k, target, nums, ds) ;
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums{1,2,3,4,5,6,7,8,9} ;
        vector<int> ds ;
        help(0, k ,n , nums, ds) ;
        
        return ans ;
    }
};