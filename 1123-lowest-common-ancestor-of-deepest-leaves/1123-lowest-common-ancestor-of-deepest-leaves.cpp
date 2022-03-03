class Solution {
public:
    int depth(TreeNode* root){
        if(!root) return 0 ;
        
        int lh= depth(root->left) ;
        int rh= depth(root->right) ;
        
        return 1 + max(lh,rh) ;
    }
        
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root) return NULL ;
        
        int lh = depth(root->left) ;
        int rh = depth(root->right) ;
        
        if(lh == rh)
            return root ;
        if(lh > rh)
            return lcaDeepestLeaves(root->left) ;
        else 
            return lcaDeepestLeaves(root->right) ;
    }
};