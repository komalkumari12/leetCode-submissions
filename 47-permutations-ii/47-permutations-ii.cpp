class Solution {
public:
    void helper(int ind, int n, vector<int> &nums, vector<vector<int>> &res, vector<int> &ds){
        if(ind>=n){
            res.push_back(ds);
            return;
        }
        unordered_set<int> s;
        
        for(int i=ind;i<n;i++){
            if(s.find(nums[i])!=s.end()){
                continue;
            }
            
            s.insert(nums[i]);
            ds.push_back(nums[i]);
            swap(nums[ind], nums[i]);
            helper(ind+1, n, nums, res, ds);
            ds.pop_back();
            swap(nums[ind], nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        helper(0, nums.size(), nums, res, ds);
        return res;
    }
};