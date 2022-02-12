class Solution {
public:
    int height(TreeNode* root){
        if(!root) return 0 ;
        
        int lh=height(root->left) ;
        if(lh==-1) return -1 ;
        
        int rh=height(root->right) ;
        if(rh==-1) return -1 ;
        
        if(abs(lh-rh)>1) return -1 ;
        
        return 1+ max(lh,rh) ;
    }
        
    bool isBalanced(TreeNode* root) {
        int result = height(root) ;
        if(result == -1) return false ;
        else  return true ;
    }
};