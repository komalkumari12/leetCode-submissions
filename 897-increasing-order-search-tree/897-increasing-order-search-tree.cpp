//Approach
//Inverse inorder traversal

class Solution {
    TreeNode* prev =NULL ;
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return NULL;
        
        increasingBST(root->right) ;
        root->right = prev ;
        
        TreeNode* leftTree = root->left ;
        root->left =NULL;
        prev= root ;
        
        increasingBST(leftTree) ;
        
        return prev;
    }
};