/* Approach
     1.Find lh and rh of every node 
     2.if absolute difference of lh and rh is greater than 1 return false
*/

class Solution {
public:
    int leftHeight(TreeNode*root){
        if(root==NULL) return 0 ;
        
        int lh=leftHeight(root->left) ;
        int rh=leftHeight(root->right) ;
        
        return 1+ max(lh,rh) ;
    }
    
    int rightHeight(TreeNode*root){
        if(root==NULL) return 0 ;
        
        int rh=rightHeight(root->right) ;
        int lh=rightHeight(root->left) ;
        
        return 1+ max(lh,rh) ;
    }
     
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true ;
        
        int lh= leftHeight(root->left) ;
        int rh= rightHeight(root->right) ;
        
        if(abs(lh-rh)>1) return false ;
        
        bool left=isBalanced(root->left) ;
        bool right=isBalanced(root->right) ;
        
        if(!left || !right) return false ;
        else return true ;
    
    }
};