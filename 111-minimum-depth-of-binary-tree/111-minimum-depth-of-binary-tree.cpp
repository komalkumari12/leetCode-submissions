class Solution {
public:
       int minDepth(TreeNode* root) {
         if(root==NULL) return 0 ;
        
        queue<TreeNode*> q ;
        q.push(root) ;
        int depth=0;
        while(!q.empty()){
            int n=q.size() ;
            
            for(int i=0 ;i< n ;i++){
                TreeNode* node=q.front();
                q.pop() ;
            
            if(node->left)
                q.push(node->left) ;
            if(node->right)
                q.push(node->right) ;
            else if(!node->left && !node->right){
                depth++ ;
                return depth ;
            } 
            }
            depth++ ;
        }
        return depth ;
    }
};

