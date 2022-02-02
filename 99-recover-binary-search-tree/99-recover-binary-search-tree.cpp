class Solution {
    TreeNode* first ;
    TreeNode* prev ;
    TreeNode* middle ;
    TreeNode* last ;
    
public:
    void inorder(TreeNode* root){
        if(root==NULL) return ;
    
        inorder(root->left) ;
        
        if(prev!=NULL  &&  root->val < prev->val){
            if(first==NULL){
                first=prev;
                middle=root;
            }
            else
                last=root;
        }
        
        prev=root ;
        inorder(root->right) ;
    }
    
    
    void recoverTree(TreeNode* root) {
        first=last=middle=NULL ;
        TreeNode* prev=new TreeNode(INT_MIN) ;
        
        inorder(root) ;
        if(first  &&  last)
            swap(first->val , last->val) ;
        else
            swap(first->val , middle->val) ;
    }
};