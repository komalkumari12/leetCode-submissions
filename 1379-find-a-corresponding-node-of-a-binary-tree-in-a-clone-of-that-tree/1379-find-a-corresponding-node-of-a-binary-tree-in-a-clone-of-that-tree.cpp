class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!original) return NULL ;
        if(original == target) return cloned ;
        
        TreeNode* leftTree =getTargetCopy(original->left ,cloned->left ,target) ;
        if(leftTree) return leftTree; 
        
        return getTargetCopy(original->right ,cloned->right ,target) ;   
    }
};