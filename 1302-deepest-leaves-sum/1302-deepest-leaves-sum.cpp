class Solution {
public:
    int height(TreeNode* root){
        if(!root) return 0 ;
        
        int left = height(root->left) ;
        int right = height(root->right) ;
        
        return 1 + max(left , right) ;
    }
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q ;
        q.push(root) ;
        int sum =0 ;
        
        int level = height(root) ;
        
        while(!q.empty()){
            int size = q.size() ;
            level-- ;
            
            for(int i=0; i<size; i++){
                TreeNode* node =q.front() ;
                q.pop() ;
                
                if(level == 0){
                    sum += node->val ;
                }
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right) ;
            
            }
        }
        
        return sum ;
    }
};