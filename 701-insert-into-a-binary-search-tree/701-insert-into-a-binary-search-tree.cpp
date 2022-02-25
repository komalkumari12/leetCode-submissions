class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            root= new TreeNode(val) ;
            return root ;
        }
        
        if(root->val > val){
            if(root->left)
                insertIntoBST(root->left,val) ;
            else{
                root->left=new TreeNode(val) ;
                return root ;
            }
        }
        
        else if(root->val < val){
            if(root->right)
                insertIntoBST(root->right, val) ;
            else{
                root->right= new TreeNode(val) ;
                return root ;
            }
        }
        
        return root ;
    }
};