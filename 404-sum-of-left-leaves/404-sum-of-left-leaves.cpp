class Solution {
public:   
    bool isLeaf(TreeNode* root){
        return (!root->left  &&   !root->right) ? true : false ;
    }
        
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        
        queue<TreeNode*> q;
        q.push(root) ;
        int leftSum =0; 
        
        while(!q.empty()){
            TreeNode* node = q.front() ;
            q.pop() ;
            
            if(node->left){
                q.push(node->left) ;
                if(isLeaf(node->left))   leftSum += node->left->val ;
            }
            if(node->right){
                q.push(node->right) ;
            }
        }
        return leftSum ;
    }
};