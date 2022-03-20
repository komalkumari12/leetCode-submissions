class Solution {
public:
    int helper(TreeNode* root){
        if(!root) return 0;
        
        int left= 1+ helper(root->left) ;
        int right= 1+ helper(root->right) ;
        
        return left+right ;
    }
    
    int countNodes(TreeNode* root) {
        return helper(root)/2 ;
    }
};