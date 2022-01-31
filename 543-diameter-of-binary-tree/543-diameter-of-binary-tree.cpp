/* Approach
    1, find lh and rh for every node
    2. store max diagonal from lh and rh in maxDiag
*/    

class Solution {
public: 
    int leftHeight(TreeNode*root){
        if(root==NULL) return 0 ;
        
        int lh=leftHeight(root->left) ;
        int rh=leftHeight(root->right) ;
        
        return 1+ max(lh, rh) ;
    }
    
    int rightHeight(TreeNode*root){
        if(root==NULL) return 0 ;
        
        int lh=rightHeight(root->right) ;
        int rh=rightHeight(root->left) ;
        
        return 1+ max(lh, rh) ;
    }
        
    void heightHelper(TreeNode* root ,int&maxDia){
        if(root==NULL) return  ;
        
        int lh=leftHeight(root->left) ;
        int rh=rightHeight(root->right) ;
        
        maxDia=max(maxDia ,lh+rh) ;
        
        heightHelper(root->left,maxDia) ;
        heightHelper(root->right,maxDia) ;
        
    }
        
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia=0 ;
        heightHelper(root ,maxDia) ;
        return maxDia ;
    }
};