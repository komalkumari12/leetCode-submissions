class Solution {
public:
    int large=0 ;
    TreeNode* bstToGst(TreeNode* root) {
        if(!root) return NULL ;
        
        bstToGst(root->right) ;
        root->val= large + root->val ;
        large=root->val ;
        bstToGst(root->left) ;
        
        return root ;
    }
};