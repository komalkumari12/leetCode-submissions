class Solution {
public:
    bool isSymmetricHelp(TreeNode* left ,TreeNode* right){
        if(!left && !right) return true ;
        if((!left  &&  right)  ||  (left  &&  !right)) return false ;
        
        if(left->val != right->val) return false ;
        
        return isSymmetricHelp(left->left , right->right)  &&   isSymmetricHelp(left->right , right->left) ;
    }
        
    bool isSymmetric(TreeNode* root) {
        return isSymmetricHelp(root->left ,root->right) ;
    }
};