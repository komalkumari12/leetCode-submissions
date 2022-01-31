class Solution {
public:    
   
        
    bool hasPathSum(TreeNode* root, int target){ 
        if(root== NULL)  return false ;
        if(!root->left && !root->right){
            if(target - root->val==0)
                return true ;
        }
        
        if(hasPathSum(root->left ,target-root->val))
            return true ;
        if(hasPathSum(root->right ,target-root->val))
            return true ;
        
        else return false ;
    }
};