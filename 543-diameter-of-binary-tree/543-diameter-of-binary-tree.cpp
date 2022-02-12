class Solution {
public:
    int maxDiameter(TreeNode* root ,int& maxDia){
        if(!root) return 0 ;
        
        int leftHeight = maxDiameter(root->left , maxDia) ;
        int rightHeight = maxDiameter(root->right , maxDia) ;
        
        maxDia = max(maxDia ,leftHeight+rightHeight) ;
        
        return 1+ max(leftHeight , rightHeight) ;
    }
        
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0; 
        
        maxDiameter(root, maxDia) ;
        return maxDia ;
    }
};

