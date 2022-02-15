class Solution {
    unordered_map<TreeNode* , int> dp ;
    
public:
    int houseRob(TreeNode* root){
        if(!root) return 0 ;
        
        if(dp.find(root) != dp.end()) return dp[root] ;
        
        int take = root->val ;
    
        if(root->left)
            take += houseRob(root->left->left) + houseRob(root->left->right) ;
        if(root->right)
            take += houseRob(root->right->left) + houseRob(root->right->right) ;
        
        int non_take = 0 + houseRob(root->left) + houseRob(root->right) ;
        
        
        return dp[root] = max(take ,non_take) ;
    }
        
    int rob(TreeNode* root) {
        return houseRob(root) ;
    }
};