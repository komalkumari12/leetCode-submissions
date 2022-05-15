class Solution {
public:
    int height(TreeNode* root){
        if(!root) return 0 ;
        
        int left=height(root->left) ;
        int right=height(root->right) ;
        
        return max(left,right) + 1;
    }
        
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0 ;
        int depth= height(root) ;
        
        queue<TreeNode*> q ;
        q.push(root) ;
        
        int sum= 0;
        int level=0 ;
        
        while(!q.empty()){
            int size=q.size() ;
            level++ ;
            
            for(int i=0; i<size ;i++){
                TreeNode* node= q.front() ;
                q.pop() ;
                
                if(level==depth)
                    sum+=node->val ;
                
                if(node->left)  q.push(node->left) ;
                if(node->right) q.push(node->right) ;
            }
        }
        
        return sum ;
    }
};