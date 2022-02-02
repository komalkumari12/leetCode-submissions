class Solution {
    vector<int>inorder ;
    int index=0 ;
public: 
    void inorderTraversal(TreeNode* root){
        if(root == NULL)  return ;
        
        inorderTraversal(root->left) ;
        inorder.push_back(root->val) ;
        inorderTraversal(root->right) ;
    }
    
    void swapNodes(TreeNode* root){
        if(root==NULL) return ;
        
        swapNodes(root->left) ;
        if(root->val != inorder[index])
            root->val = inorder[index] ;
        index++ ;
        swapNodes(root->right) ;     
    }
        
    void recoverTree(TreeNode* root) {
        inorderTraversal(root) ;
        sort(inorder.begin() , inorder.end()) ;
        
        swapNodes(root) ;  
    }
};