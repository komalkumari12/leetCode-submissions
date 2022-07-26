class Solution {
public:
    bool find(TreeNode* root, int limit, int sum){
        if(!root) return false ;
        
        if(!root->left && !root->right){
            sum += root->val ;
            if(sum >= limit) return true ;
            return false ;
        } 
        
        bool left = find(root->left, limit, sum+root->val) ;
        bool right = find(root->right, limit, sum+root->val) ;
        
        if(!left)   root->left =NULL ;
        if(!right)  root->right =NULL ;
        if(left || right) return true ;
        
        return false ;
    }
        
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        bool ans =find(root,limit, 0) ;
        if(!ans)
            return  NULL ;
        return root ;
    }
};