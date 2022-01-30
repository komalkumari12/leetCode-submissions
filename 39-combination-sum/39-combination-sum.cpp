class Solution {
public:
    void sum( int index ,int  target, vector<int>& candidates , vector<vector<int>>&ans , vector<int>& arr ){
        if(index == candidates.size()){
            if(target == 0){
                ans.push_back(arr) ;
            }
            return ;
        }
        
        if(candidates[index] <= target){
            arr.push_back(candidates[index]) ;
            sum(index ,target - candidates[index], candidates , ans, arr) ;
            
            arr.pop_back() ;
        }
        sum(index + 1 ,target, candidates  ,ans, arr) ;
    } 
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans ;
        vector<int> arr ;
        
        sum(0, target ,candidates , ans, arr ) ;
        
        return ans ;
    }
};