/* Approach
     1. find the max height at of all nodes
     2. if at any given time height rh or lh becommes equal to -1  OR  absolute difference of lh and rh becomes -1 return false 
     3. else tree is balanced binary tree
*/     
     
class Solution {
public:
    int check(TreeNode* root){
        if(root==NULL) return 0 ;
        
        int lh=check(root->left) ;
        if(lh==-1) return -1 ;
        int rh=check(root->right) ;
        if(rh==-1) return -1 ;
    
        if(abs(lh-rh) > 1) return -1;
        
        return 1+max(lh,rh) ;
    }
        
    bool isBalanced(TreeNode* root) {
        int result =check(root) ;
        if(result==-1)
            return false ;
        else
            return true ;   
    }
};