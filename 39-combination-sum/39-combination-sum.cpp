class Solution {
public:
    void sum(int ind ,int target ,vector<int>& candidates ,vector<vector<int>>&ans ,vector<int>& ds){
        if(ind == candidates.size()){
            if(target==0){
                ans.push_back(ds) ;
            }
            return  ;
        }
        //pick 
        if(candidates[ind] <= target ){
            ds.push_back(candidates[ind]) ;
            sum(ind ,target-candidates[ind] ,candidates ,ans ,ds) ;
            ds.pop_back() ;
        }
        
        sum(ind+1,target ,candidates ,ans,ds) ;
        
    }
        
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans ;
        vector<int> ds ;
        
        sum(0, target ,candidates , ans, ds) ;
        return ans; 
    }
};