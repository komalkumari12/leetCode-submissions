class Solution {
public:
    void  preOrder(TreeNode* root, int maxNodeInPath, int& count){
        if(!root)   return ;
        
        if(root->val >= maxNodeInPath){
            count++ ;
            maxNodeInPath = root->val ;
        }
        
        preOrder(root->left, maxNodeInPath, count) ;
        preOrder(root->right, maxNodeInPath, count) ;
    }
        
    int goodNodes(TreeNode* root) {
        int count =0 ;
        preOrder(root, INT_MIN, count) ;
        
        return count ;
    }
};