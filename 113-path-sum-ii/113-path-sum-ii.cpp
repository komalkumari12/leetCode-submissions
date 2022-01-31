class Solution {
public:
    void helper(TreeNode* root, int target, vector<int>&ds, vector<vector<int>>&ans){
        if(root==NULL) return ;
        
        if(!root->left && !root->right){
            if(target-root->val == 0){
                ds.push_back(root->val) ;
                ans.push_back(ds) ;
                ds.pop_back() ;
            }
            return ;
        }
        ds.push_back(root->val) ;
        helper(root->left, target-root->val ,ds,ans) ;
        helper(root->right, target-root->val ,ds,ans) ;
        ds.pop_back() ;
    }
        
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans ;
        if(root==NULL) return ans ;
        
        vector<int> ds ;
        helper(root, targetSum, ds, ans) ;
        
        return ans ;
    }
};