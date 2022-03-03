class Solution {
    int maxi= 0;
public:
    void  greaterSumTree(TreeNode* root){
        if(!root) return ;
        
        greaterSumTree(root->right) ;
        
        root->val = root->val + maxi ;
        maxi=root->val  ;
        
        greaterSumTree(root->left) ;   
    }
        
    TreeNode* convertBST(TreeNode* root) {
        
        greaterSumTree(root) ;
        return root ;
    }
};